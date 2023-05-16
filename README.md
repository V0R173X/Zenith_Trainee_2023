# Zenith_Trainee_2023
Repositório destinado a conter minha solução da segunda fase do processo seletivo da Zenith

Decidi realizar a simulação dos dados da sonda no Wokwi.

Iniciamos com a inserção de um sensor térmico NTC. Como este sensor registra a temperatura por uma alteração de tensão, a leitura dos dados de entrada deste sensor devem ser feitos em uma porta analógica do micro-controlador. Por conta do ADC interno à esp32, a variação de tensão (de 0 a 3.3V) é expressa em uma escala de 12-bits (de 0 a 4095), quando olhamos as referências presentes no Wokwi em relação a este sensor, existe uma relação que converte esta captação de 0 a 4095 em graus Celsius correspondentes. Um problema enfrentado inicialmente nesta etapa é que esta referência do Wokwi refere-se a uma escala de 10-bits (0 a 1023) presente no arduino, portanto antes de utilizar a função dada precisamos converter nossos dados analogicos da escala de 12-bits para a escala de 10-bits, sendo assim possível de utilizar a fórmula dada nas referências do Wokwi. Em simulação, por meio de escrita dos dados no monitor serial, é possível verificar que os valores obtidos de temperatura tem uma incerteza de no máximo 0.25 ºC em relação aos valores reais.

Após isso foi pensado a implementação de um sensor ultrassônico para que pudesse captar quando um objeto se aproximasse demasiadamente produzindo alguma saída boa o suficiente para alertar o que quer que estivesse se aproximando (Seria algo idealmente útil apenas em casos muito específicos, mas não há melhores sensores, como barômetro, implementados no wokwi). Para realizar sua implementação foi baseado nas referências de utilização dadas pelo próprio Wokwi. Inicialmente pretendia-se conectar 6 sensores ultrassônicos, imaginando a sonda como um cubo haveria um sensor para cada face, porém o Wokwi apresentou falhas durante a implementação do segundo sensor ultrassônico, mesmo sendo utilizado o mesmo procedimento que o primeiro, e até mesmo mudando as portas de utilização dos dois sensores, o primeiro sensor sempre funcionava mas o segundo não apresentava valores para a distância. Diante deste problema, optou-se por manter apenas um sensor, podendo ser direcionado para a face superior, por exemplo. A funcionalidade do sensor foi testada por meio de escritas no monitor serial.

Com a implementação dos dois sensores, agora partimos para as saídas. COmo requirido, teremos uma saída visual expressa por LEDs, temos quatro LEDs colocados que serão acesos para um intervalo específico de temperatura captado, um azul (para valores de temperatura abaixo de 2ºC), um verde (para valores acima de 2ºC e abaixo de 28ºC), um amarelo (para valores acima de 28ºC e abaixo de 54ºC) e um vermelho (para valores acima de 54ºC). Essa divisão foi estabelecidade para ter uma quantidade igual de valores para cada cor dado o espectro de temperaturas possíveis de serem simuladas no Wokwi (de -24ºC até 80ºC). A implementação correu bem, lembrando sempre de utilizar um resistor ligado ao cátodo antes de conectá-lo à alguma porta da esp32, para que quando definir a porta digital com tensão máxima não acabar queimando o LED.

Outra saída definida foi a utilização do buzzer para quando o sensor ultrassônico detecta algo em uma distância menor que 1.5m. Caso a distância seja menor que 1.5m o buzzer começará a tocar um som com frequência de 500Hz. Com isto implementado, para cada sensor temos uma forma de saída, finalizando o desenvolvimento da simulação de esp32. O código será anexado juntamente no repositório junte de uma printscreen durante a simulação para apresentar a montagem do sistema. Para maiores verificações do projeto pode-se acessar o próprio link da montagem no Wokwi, sendo o link de acesso: https://wokwi.com/projects/364853964089968641.
