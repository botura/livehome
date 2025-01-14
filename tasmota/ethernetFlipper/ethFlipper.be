# https://tasmota.github.io/docs/Berry-Cookbook/#ethernet-network-flipper
# Ethernet Network Flipper - checks every 30 seconds if ethernet if up
# if Ethernet is up, Wifi is turned off to avoid interference with Zigbee
# if Ethernet is down, Wifi is turned back on to allow fallback connection

def netflip()
  # store variable "eth" with Ethernet status - "true" if Ethernet IP exists and "false" if not
  var eth = tasmota.eth('up')

  # check if wifi and eth are both up or both down
  if tasmota.wifi('up') == eth
    # send command Wifi with parameter depending on eth variable, turn Wifi on if eth is down, turn Wifi off if eth is up
    tasmota.cmd('Wifi ' + (eth ? '0' : '1'))
  end

  # set a timer to execute the netflip function every 30000ms (30 seconds)
  tasmota.set_timer(30000, netflip)
end

# set a timer to execute the netflip function 30000ms (30 seconds) after loading autoexec.be
tasmota.set_timer(30000, netflip)
