# Modbus driver

class Modbus : Driver
  var server # tcpserver
  var connection # tcpconnection
  var state # machine state
  var rxData # received data
  var txData # data to send
  var outputState # output state, ex. bytes("FFFF") mean all outputs are on

  # states
  var STATE_BOOTING
  var STATE_OPEN_SOCKET
  var STATE_WAITING_CLIENT
  var STATE_CLIENT_CONNECTED
  var STATE_CLIENT_DISCONNECTED
  var STATE_CLOSE_SOCKET


  # constructor
  def init()
    self.STATE_BOOTING = 0
    self.STATE_OPEN_SOCKET = 1
    self.STATE_WAITING_CLIENT = 2
    self.STATE_CLIENT_CONNECTED = 3
    self.STATE_CLIENT_DISCONNECTED = 4
    self.STATE_CLOSE_SOCKET = 5

    self.state = self.STATE_BOOTING
    self.rxData=bytes()
    self.txData=bytes()
    self.outputState = bytes(-2)
    print("Modbus driver initialized")
  end


  # modbus crc16
  # https://gist.github.com/deldrid1/3839697
  def crc16(data)
    var hiCRCList = bytes("00C1814001C0804101C0804100C1814001C0804100C1814000C1814001C0804101C0804100C1814000C1814001C0804100C1814001C0804101C0804100C1814001C0804100C1814000C1814001C0804100C1814001C0804101C0804100C1814000C1814001C0804101C0804100C1814001C0804100C1814000C1814001C0804101C0804100C1814000C1814001C0804100C1814001C0804101C0804100C1814000C1814001C0804101C0804100C1814001C0804100C1814000C1814001C0804100C1814001C0804101C0804100C1814001C0804100C1814000C1814001C0804101C0804100C1814000C1814001C0804100C1814001C0804101C0804100C18140")
    var lowCRCList = bytes("00C0C101C30302C2C60607C705C5C404CC0C0DCD0FCFCE0E0ACACB0BC90908C8D81819D91BDBDA1A1EDEDF1FDD1D1CDC14D4D515D71716D6D21213D311D1D010F03031F133F3F23236F6F737F53534F43CFCFD3DFF3F3EFEFA3A3BFB39F9F83828E8E929EB2B2AEAEE2E2FEF2DEDEC2CE42425E527E7E62622E2E323E12120E0A06061A163A3A26266A6A767A56564A46CACAD6DAF6F6EAEAA6A6BAB69A9A86878B8B979BB7B7ABABE7E7FBF7DBDBC7CB47475B577B7B67672B2B373B17170B0509091519353529296565797559594549C5C5D9D5F9F9E5E5A9A9B5B99595898884849894B8B8A4A4E8E8F4F8D4D4C8C44848545874746868242438341818040")
    var hiCRC = 0xFF
    var lowCRC = 0xFF
    var indexCRC = 0
    var i = 0
    while (i < data.size())
      indexCRC = lowCRC ^ data[i]
      lowCRC = hiCRC ^ hiCRCList[indexCRC]
      hiCRC = lowCRCList[indexCRC]
      i += 1
    end
    var crc = bytes(-2)
    crc[1] = hiCRC
    crc[0] = lowCRC
    return crc
  end


  # analyse received data
  def analyseData()
    if (self.rxData == bytes("0101000000103DC6"))
      # print("bingo")
      # create response
      self.txData = bytes("010102") + self.outputState
      # add crc16 to response
      self.txData += self.crc16(self.txData)
      # send response
      self.connection.write(self.txData)
    end
  end


  # state machine
  def executeMachineState()
    if (self.state == self.STATE_BOOTING)
      print("STATE_BOOTING")
      self.state = self.STATE_OPEN_SOCKET
      
    elif (self.state == self.STATE_OPEN_SOCKET)
      self.server = tcpserver(502)
      print(self.server)
      self.state = self.STATE_WAITING_CLIENT
      print("Going to STATE_WAITING_CLIENT")

    elif (self.state == self.STATE_WAITING_CLIENT)
      if (self.server.hasclient())
        print("Going to STATE_CLIENT_CONNECTED")
        self.connection = self.server.accept()
        self.state = self.STATE_CLIENT_CONNECTED
      end

    elif (self.state == self.STATE_CLIENT_CONNECTED)
      self.rxData = self.connection.readbytes()
      if (self.rxData.size() > 0)
        # data has been received, analyse it
        self.analyseData()
      end
      if (!self.connection.connected())
        # connection is closed
        print ("Conction closed")
        self.state = self.STATE_CLIENT_DISCONNECTED
        print("Going to STATE_CLIENT_DISCONNECTED")
      end

    elif (self.state == self.STATE_CLIENT_DISCONNECTED)
      self.connection.close()
      self.state = self.STATE_WAITING_CLIENT
      print("Going to STATE_WAITING_CLIENT")

    elif (self.state == self.STATE_CLOSE_SOCKET)
      self.state = self.STATE_BOOTING
    end
  end

  # every_50ms
  def every_50ms()
    # update output state
    for i: 0..15
      self.outputState.setbits(i, 1, tasmota.get_power()[i])
    end
  end

# fast loop
  def fast_loop()
    self.executeMachineState()
  end

end

# create instance of IOR_Modbus
modbus = Modbus()
tasmota.add_driver(modbus)
tasmota.add_fast_loop(/-> modbus.fast_loop())
