import numpy as np
import matplotlib.pyplot as plt
import random
import math
import matplotlib.pyplot as plt
import numpy as np

# Definição das variáveis
matrix_size = 50  # Tamanho da matriz
num_agents = 100  # Número de agentes
num_predators = 500  # Número de predadores
num_symbols = 10  # Número de símbolos por agente
num_iterations = 100  # Número de iterações
rp = 3  # Raio de percepção da presença de predadores
ra = 2  # Raio de percepção de alarmes

# Função para obter a posição do predador (exemplo simples)
def get_predator_position(predator_id):
    position = (np.random.randint(0, matrix_size), np.random.randint(0, matrix_size))
    return position

# Função para calcular a distância entre duas posições
def distance(pos1, pos2):
    x1, y1 = pos1
    x2, y2 = pos2
    return math.sqrt((x2 - x1)**2 + (y2 - y1)**2)

# Geração aleatória dos pesos iniciais para os símbolos de cada agente
initial_symbol_weights = np.random.rand(num_agents, num_symbols)

# Inicialização dos pesos finais dos símbolos e predadores
final_symbol_weights = np.zeros((num_agents, num_symbols))
final_predator_weights = np.zeros((num_predators, num_symbols))

# Simulação das interações
for iteration in range(num_iterations):
    # Movimentação aleatória dos agentes
    agent_positions = [(np.random.randint(0, matrix_size), np.random.randint(0, matrix_size)) for _ in range(num_agents)]
    
    # Verificação de predadores e disparo de alarmes pelos agentes
    for agent_id in range(num_agents):
        agent_position = agent_positions[agent_id]
        alarms = initial_symbol_weights[agent_id]
        predator_positions = [get_predator_position(predator_id) for predator_id in range(num_predators)]
        
        for predator_id in range(num_predators):
            predator_position = predator_positions[predator_id]
            if predator_position is not None and distance(agent_position, predator_position) <= rp:
                # Agente percebe a presença do predador e dispara o alarme
                max_alarm = np.argmax(alarms)
                final_symbol_weights[agent_id][max_alarm] += 0.1

# Plotar gráficos cruzando Iterações X Pesos (f) para alguns agentes m
agent_ids = [0, 1, 2]  # IDs dos agentes a serem plotados
plt.figure(figsize=(12, 8))
for agent_id in agent_ids:
    plt.plot(final_symbol_weights[agent_id], label='Agente {}'.format(agent_id))
plt.xlabel('Símbolos')
plt.ylabel('Pesos (f)')
plt.title('Pesos (f) dos Símbolos Finais para Agentes Selecionados')
plt.legend()
plt.show()

# Plotar gráficos cruzando Iterações X Pesos (f) para alguns predadores p
predator_ids = [0, 1, 2]  # IDs dos predadores a serem plotados

# Criar uma figura com subplots para cada predador
fig, axs = plt.subplots(len(predator_ids), 1, figsize=(12, 8), sharex=True)

# Iterar pelos IDs dos predadores
for i, predator_id in enumerate(predator_ids):
    # Obter os pesos finais do predador
    predator_weights = final_predator_weights[predator_id]

    # Plotar o gráfico do predador atual
    axs[i].plot(predator_weights)
    axs[i].set_ylabel('Pesos (f)')
    axs[i].set_title('Predador {}'.format(predator_id))

# Definir o rótulo do eixo x no último subplot
axs[-1].set_xlabel('Símbolos')

# Ajustar o espaçamento entre os subplots
plt.tight_layout()

# Exibir o gráfico
plt.show()

# Plotar gráficos cruzando Iterações X Pesos (f) para cada predador p
plt.figure(figsize=(12, 8))
for agent_id in range(num_agents):
    plt.plot(final_symbol_weights[agent_id], label='Agente {}'.format(agent_id))
plt.xlabel('Símbolos')
plt.ylabel('Pesos (f)')
plt.title('Pesos (f) dos Símbolos Finais para Todos os Agentes')
plt.legend()
plt.show()



# Apresentar imagens do ambiente de interação dos agentes
matrix = np.zeros((matrix_size, matrix_size))
for agent_position in agent_positions:
    x, y = agent_position
    matrix[x, y] = 1  # Representar agentes com o valor 1 na matriz
for predator_position in predator_positions:
    if predator_position is not None:
        x, y = predator_position
        matrix[x, y] = 2  # Representar predadores com o valor 2 na matriz

plt.figure(figsize=(8, 8))
plt.imshow(matrix, cmap='Greys', origin='lower')
plt.title('Ambiente de Interação dos Agentes')
plt.show()




# Valores fictícios para demonstração
final_predator_weights = {
    0: [0.3, 0.5, 0.8, 0.7, 0.9],
    1: [0.6, 0.4, 0.2, 0.1, 0.3],
    2: [0.9, 0.7, 0.4, 0.6, 0.2]
}
predator_ids = [0, 1, 2]

# Criar uma figura com subplots para cada predador
fig, axs = plt.subplots(len(predator_ids), 1, figsize=(12, 8), sharex=True)

# Iterar pelos IDs dos predadores
for i, predator_id in enumerate(predator_ids):
    # Obter os pesos finais do predador
    predator_weights = final_predator_weights[predator_id]

    # Plotar o gráfico do predador atual
    axs[i].plot(predator_weights)
    axs[i].set_ylabel('Pesos (f)')
    axs[i].set_title('Predador {}'.format(predator_id))

# Definir o rótulo do eixo x no último subplot
axs[-1].set_xlabel('Iterações')

# Ajustar o espaçamento entre os subplots
plt.tight_layout()

# Exibir o gráfico
plt.show()



# Definição das variáveis e códigos anteriores...

# Threshold para os valores a serem plotados
threshold = 1

# Plotar gráficos cruzando Iterações X Pesos (f) para cada predador p
plt.figure(figsize=(12, 8))
for agent_id in range(num_agents):
    # Aplicar a máscara condicional para selecionar apenas os valores acima do threshold
    mask = final_symbol_weights[agent_id] > threshold
    plt.plot(final_symbol_weights[agent_id][mask], label='Agente {}'.format(agent_id))

plt.xlabel('Símbolos')
plt.ylabel('Pesos (f)')
plt.title('Pesos (f) dos Símbolos Finais para Todos os Agentes (Valores Acima do Limite)')
plt.legend()
plt.show()