# O drive original do Tasmota para o 74595 atualiza o estado das saídas apenas quando tem algum comando novo para as saídas
# Com esse driver o estado das saídas é atualizado a cada 1s
# Dessa forma, caso ocorra alguma falha (por ruído ou alimentação), o estado das saídas será corrigido rapidamente

class IOR_Saidas : Driver
  # inicializa o drive
  def init()
      print("Driver IOR_Saidas inicializado")
  end

  # Le a primeira saida e atualiza o estado dela mesma, dessa forma o Tasmota atualiza o estado dos 74595
  def atualizaSaidas()
    # print("Atualizando saídas")
    tasmota.set_power(0, tasmota.get_power()[0])
  end

  # # every_100ms
  # def every_100ms()
  #   # update inputs
  #   self.atualizaSaidas()
  # end
    
  # every_second
  def every_second()
    # atualiza as saidas
    self.atualizaSaidas()
  end

end

iorSaidas = IOR_Saidas()
tasmota.add_driver(iorSaidas)