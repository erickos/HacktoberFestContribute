import sys
import copy

class Node:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.left_nodes = 0
        self.right_nodes = 0
        self.data = key


def busca_binaria(root, value):
    if not root:
        return False

    if root.data == value:
        return True
    elif root.data > value:
        return busca_binaria(root.right, value)
    else:
        return busca_binaria(root.left, value)


def remover_no(root, data):
    if not root:
        return None

    if data < root.data:
        root.left = remover_no(root.left, data)
    elif data > root.data:
        root.right = remover_no(root.right, data)
    else:

        if root.left is None and root.right is None:
            root = None

        elif root.left is None:
            temp = root
            root = root.right


        elif root.right is None:
            temp = root
            root = root.left

        else:
            temp = min_value(root, root.right)
            root.data = temp.data
            root.right = remover_no(root.right, temp.data)

    return root


def min_value(root, node):
    if root == None:
        print("Árvore vazia!")
    else:
        while(node.left != None):
            node = node.left
        return (node)


def insira(root, node):
    exists = True
    if root.data == node.data:
        print(f'>>> ERRO: O valor {node.data} não pôde ser adicionado pois já existe na árvore.')
        return False

    elif root.data < node.data:
        if root.right is None:
            root.right = node

        else:
            exists = insira(root.right, node)


        if exists: root.right_nodes += 1
        return exists

    else:
        if root.left is None:
            root.left = node

        else:
            exists = insira(root.left, node)


        if exists: root.left_nodes += 1
        return exists


def atualiza_nos(root):
    root.left_nodes = 0
    root.right_nodes = 0

    if root.right:
        root.right_nodes += atualiza_nos(root.right)
    if root.left:
         root.left_nodes += atualiza_nos(root.left)

    return root.left_nodes + root.right_nodes + 1


def get_height(node):
    if not node:
        return 0

    if node.left and node.right:
        return 1 + max(get_height(node.left), get_height(node.right))

    elif node.left:
        return 1 + get_height(node.left)

    elif node.right:
        return 1 + get_height(node.right)

    else:
        return 1


def enesimo_elemento(root, n):
    size = root.left_nodes + root.right_nodes + 1

    if not root or n <= 0 or n > size:
        return None


    if n <= root.left_nodes:
        return enesimo_elemento(root.left, n)

    elif n == root.left_nodes + 1:
        return root

    else:
        return enesimo_elemento(root.right, n - root.left_nodes - 1)


def posicao(root, x):
    current = root
    s = []
    done = 0
    count = 1

    while(not done):
        if current is not None:
            s.append(current)
            current = current.left
        else:
            if(len(s) > 0):
                current = s.pop()
                if current.data == x:
                    return count
                current = current.right
                count += 1
            else:
                done = 1

    return 0


def mediana(root):
    size = root.left_nodes + root.right_nodes + 1
    med = 0
    if size % 2 == 0:
        med = size // 2
    else:
        med = (size // 2) + 1

    return enesimo_elemento(root, med).data


def eh_cheia(root):
    h = get_height(root)
    size = root.left_nodes + root.right_nodes + 1

    return size == ((2 ** h) - 1)


def eh_completa(root, index, n_nodes):
    if root is None:
        return True

    if index >= n_nodes :
        return False

    return (eh_completa(root.left , 2*index+1, n_nodes)
        and eh_completa(root.right, 2*index+2, n_nodes))


def to_string(root):
    if not root:
        return

    queue = []
    queue.append(root)

    while len(queue) > 0:
        print(queue[0].data, end=' ')
        node = queue.pop(0)

        if node.left:
            queue.append(node.left)

        if node.right:
            queue.append(node.right)

    print("")


def inserir(root, nodes):
    for node in nodes:
        insira(root, node)


if __name__ == "__main__":
    if len(sys.argv) < 3:
        print("Número inválido de argumentos!")
        exit()

    inputs = open(sys.argv[1], "r")

    #checks if the first entry are the values to insert on tree
    string = str(inputs.readline().split(' ')[0])
    if not string.isdigit():
        print(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> ERRO <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<")
        print("O primeiro arquivo deve conter os valores a serem inseridos na árvore.\nVerifique a entrada!")
        exit()

    #returns to the beginning of the buffer
    inputs.seek(0)

    #reads all the values
    values = list(map(int, inputs.readline().split(' ')))
    root = Node(values.pop(0))
    nodes = [Node(value) for value in values]

    #inserts all the values on the tree
    inserir(root, nodes)
    print()

    commands = open(sys.argv[2], "r")
    for index, command in enumerate(commands):
        command_, argument = command.replace('\n', ' ').split(' ', 1)
        print(f'============ COMANDO: {command_} - Argumento(s): {argument}=============')

        if command_ == 'ENESIMO':
            no = enesimo_elemento(root, int(argument))
            if no:
                print(f'Elemento na posição {argument} -> {no.data}')
            else:
                print(f'>>> ERRO: A arvore não possui um {argument}° elemento')

        elif command_ == 'POSICAO':
            position = posicao(root, int(argument))

            if position:
                print(f'Posição do elemento {argument} -> {position}')
            else:
                print(f'>>> ERRO: O elemento {int(argument)} não está na árvore.')

        elif command_ == 'MEDIANA':
            print(f'Elemento da posição mediana -> {mediana(root)}')

        elif command_ == 'CHEIA':
            print(f'Árvore é cheia? -> {eh_cheia(root)}')

        elif command_ == 'COMPLETA':
            n_nodes = root.left_nodes + root.right_nodes + 1
            print(f'Árvore é completa? -> {eh_completa(root, 0, n_nodes)}')

        elif command_ == 'IMPRIMA':
            print('Valores da árvore por níveis:')
            to_string(root)

        elif command_ == 'INSIRA':
            flag = insira(root, Node(int(argument)))
            if flag:
                print(f'O valor {argument} foi adicionado!')

        elif command_ == 'REMOVA':
            aux = copy.copy(root)
            root = remover_no(root, int(argument))
            atualiza_nos(root)
            if (aux.left_nodes + aux.right_nodes) == (root.left_nodes + root.right_nodes):
                print(f'>>> ERRO: O valor {argument} não existe na árvore')
            else:
                print(f'O valor {argument} foi removido com sucesso!')

        elif command_ == 'BUSCA':
            flag = busca_binaria(root, int(argument))
            if flag:
                print(f'O valor {argument} se encontra na árvore.')
            else:
                print(f'O valor {argument} NÃO encontra na árvore.')

        else:
            print('Nenhum comando correspondente encontrado!')
