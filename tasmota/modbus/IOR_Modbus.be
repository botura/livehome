# Drive para modbus

import string

class IOR_Modbus : Driver
  var server
  var connection
  var estado
  var efeDelayLoop
  var rxData
  var txData

  var ESTADO_BOOTING
  var ESTADO_OPEN_SOCKET
  var ESTADO_WAITING_CLIENT
  var ESTADO_CLIENT_CONNECTED
  var ESTADO_CLIENT_DISCONNECTED
  var ESTADO_CLOSE_SOCKET
  var SCAN_DELAY


  # inicializa o drive
  def init()
    self.ESTADO_BOOTING = 0
    self.ESTADO_OPEN_SOCKET = 1
    self.ESTADO_WAITING_CLIENT = 2
    self.ESTADO_CLIENT_CONNECTED = 3
    self.ESTADO_CLIENT_DISCONNECTED = 4
    self.ESTADO_CLOSE_SOCKET = 5

    self.SCAN_DELAY = 1
    self.estado = self.ESTADO_BOOTING
    self.efeDelayLoop = 0
    self.rxData=bytes()
    self.txData=bytes()
    print("Driver IOR_Modbus inicializado")
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

  # var data = bytes("010102FFFF")
  # var crc = crc16(data)
  # print("CRC-16: 0x" + crc.tohex())

  # Trata o pacote recebido
  def trataPacote()
    # print (str(self.rxData))
    if (self.rxData == bytes("0101000000103DC6"))
      # print("bingo")
      self.txData = bytes("010102FFFF")
      self.txData += self.crc16(self.txData)
      # self.connection.write(bytes("010102FFFFB84C"))
      self.connection.write(self.txData)
    end
  end

  # Le a primeira saida e atualiza o estado dela mesma, dessa forma o Tasmota atualiza o estado dos 74595
  def executa()
    if (self.estado == self.ESTADO_BOOTING)
      print("ESTADO_BOOTING")
      # tasmota.log("ESTADO_BOOTING")

      self.estado = self.ESTADO_OPEN_SOCKET
      
    elif (self.estado == self.ESTADO_OPEN_SOCKET)
      self.server = tcpserver(502)
      print(self.server)
      self.estado = self.ESTADO_WAITING_CLIENT
      print("Indo para ESTADO_WAITING_CLIENT")

    elif (self.estado == self.ESTADO_WAITING_CLIENT)
      if (self.server.hasclient())
        print("Indo para ESTADO_CLIENT_CONNECTED")
        self.connection = self.server.accept()
        self.estado = self.ESTADO_CLIENT_CONNECTED
      end

    elif (self.estado == self.ESTADO_CLIENT_CONNECTED)
      self.rxData = self.connection.readbytes()
      if (self.rxData.size() > 0)
        self.trataPacote()
        # print (str(self.rxData))
      end

      # verifica se a conexão foi encerrada
      if (!self.connection.connected())
        print ("Conexão encerrada")
        self.estado = self.ESTADO_CLIENT_DISCONNECTED
        print("Indo para ESTADO_CLIENT_DISCONNECTED")

      end

    elif (self.estado == self.ESTADO_CLIENT_DISCONNECTED)
      self.connection.close()
      self.estado = self.ESTADO_WAITING_CLIENT
      print("Indo para ESTADO_WAITING_CLIENT")

    elif (self.estado == self.ESTADO_CLOSE_SOCKET)
      self.estado = self.ESTADO_BOOTING
    end
  end

  # executa o drive a cada 50ms
  def every_50ms()
    if (self.efeDelayLoop >= self.SCAN_DELAY)
      self.executa()
      self.efeDelayLoop = 0
    end
    self.efeDelayLoop += 1

  end

end

iorModbus = IOR_Modbus()
tasmota.add_driver(iorModbus)