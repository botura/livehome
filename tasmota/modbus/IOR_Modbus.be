# Drive para modbus

import string

class IOR_Modbus : Driver
  var server
  var connection
  var estado
  var efeDelayLoop
  var packet

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
    self.packet=bytes()
    print("Driver IOR_Modbus inicializado")
  end

  # Trata o pacote recebido
  def trataPacote()
    # print (str(self.packet))
    if (self.packet == bytes("0101000000103DC6"))
      # print("bingo")
      self.connection.write(bytes("010102FFFFB84C"))
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
      self.packet = self.connection.readbytes()
      if (self.packet.size() > 0)
        self.trataPacote()
        # print (str(self.packet))
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