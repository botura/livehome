
- Como fazer driver para o Tasmota
https://github.com/phpcoder/tasmota-custom-integration

https://templates.blakadder.com/wireless_tag_WT32-ETH01.html

https://community.home-assistant.io/t/how-to-install-newer-tasmota-versions-on-the-wt32-eth01-a-physical-networked-esp32/657193/14




### Configuração
Basta gravar o firmware padrão para o ESP32 (pode ser via navegador ou pelo vscode) e aplicar o template:

```
{"NAME":"WT32-ETH01","GPIO":[1,1,1,1,1,1,0,0,1,0,1,1,3840,576,5600,0,0,0,0,5568,0,0,0,0,0,0,0,0,1,1,0,1,1,0,0,1],"FLAG":0,"BASE":1,"CMND":"GPIO2 8288|GPIO4 8320|GPIO14 8352|GPIO15 8384|SetOption36 0|Shift595DeviceCount 2|EthAddress 1|EthClockMode 0"}
```
```
SetOption36 0
Shift595DeviceCount 2
EthAddress 1
EthClockMode 0
```
