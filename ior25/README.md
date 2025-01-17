# Firmware 2025 da placa IOR 16E/16S

## TODO List
- Possibilidade de configurar cenários. A idéia é habilitar essa função configurando registros via modbus. O cenário é ativado por uma entrada digital.

  - Criar registros de cenários. Por exemplo vamos dizer que a placa aceita até 8 cenários. Então a placa teria 16 registros de programação desses cenários, 8 para indicar quais saídas serão ligadas e 8 para indicar quais serão desligadas. Ex:
  - Registro 1 - Cenário 1, saídas ON: 0x0003 - S0 e S1 serão ligadas
  - Registro 2 - Cenário 1, saídas OFF: 0x0004 - S3 será desligada

- O ideal acho que é cada entrada ter um registro para definir a função dessa entrada, ex:
  - 0xXXYY: onde XX seria a função e YY algum parâmetro
  - 0x0000: função 0, inverter saída (padrão)
  - 0x0102: função 1, executa cenário 2
  - 0x0203: funcao 2, executa cenário 3 se pressionada por um tempo, pulso rápido tem a função padrão.

- Além disso, poderia ter a possibilidade de executar um cenário a partir de um comando modbus. Ter um registro que executa determinada função de acordo com o valor escrito pelo modbus, ex:
  - 0xXXYY: onde XX seria a função e YY algum parâmetro
  - 0x0102: função 1, executar cenário 2


Resumo dos registros:
- 16 registros para indicar a função e parâmetro de cada entrada
- 8 registros para indicar quais saídas serão ligadas num determinado cenário (8 cenários)
- 8 registros para indicar quais saídas serão desligadas num determinado cenário (8 cenários)
- 1 registro para ativar cenário via modbus