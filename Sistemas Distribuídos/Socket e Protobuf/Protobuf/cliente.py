import socket

def main():
    HOST = "localhost"
    PORT = 5000
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock.connect((HOST, PORT))

    sair = True
    data = ""
    while bool(sair):
        opcao = int(input('''
        \n\n# MENU PRINCIPAL #\n
        1 - Criar contato
        2 - Procurar contato
        3 - Atualizar contato
        4 - Remover contato
        0 - Sair
        - > '''))
        print("Sua escolha foi:", opcao)
        if opcao == 1:
            nome = ''
            endereco = ''
            email = ''
            telefones = ''
            print("\nNOVO CONTATO\n") 
            nome = input('Digite o nome do novo contato: ')
            endereco = input('Digite o endereco do novo contato: ')
            email = input('Digite o email do novo contato: ')
            telefones = input('Digite o numero de telefones do novo contato (N telefones com "+" entre eles): ')
            
            contato = "1_" + nome +"_"+ endereco + "_"+ email + "_" + telefones + "\n"
            print("Mensagem que sera mandada para o server: " + contato)
            
            sock.sendto(contato.encode(),(HOST, PORT)) #enviando dados para o servidor
            data = sock.recv(2000).decode() #Recebendo dados do servidor
            
            if len(data) == 1: #solucao de um bug
                data = sock.recv(1024).decode()
            
            print("Mensagem recebida do servidor:", data)
            pass
        elif opcao == 2:
            print("\nPROCURAR CONTATO\n")
            nome = '' 
            nome = input('Digite o nome a ser procurado: ')
            contato = "2_"+ nome + "\n"
            sock.sendto(contato.encode(),(HOST, PORT)) #enviando para o servidor
            data = ''
            data = sock.recv(1024).decode()

            if len(data) == 1:
                data = sock.recv(1024).decode()
            print("Mensagem recebida do servidor:", data)
            data = ''
            pass
        elif opcao == 3: #UPDATE
            print("\nATUALIZAR CONTATO\n")
            nome = '' 
            nome = input('Digite o nome a ser atualizado: ')
            contato = "3_"+ nome + "\n"
            sock.sendto(contato.encode(),(HOST, PORT)) #enviando para o servidor
            data = ''
            data = sock.recv(1024).decode()

            if len(data) == 1:
                data = sock.recv(1024).decode()

            if data == 'Nao encontrei nenhum contato':
                print('Nao encontrei nenhum contato')
            else:
                print("Contato encontrado ---- ", data)
                contato2 = ''
                print("\nDADOS NOVOS DO CONTATO")
                nome = ''
                endereco = ''
                email = ''
                telefones = ''
                nome = input('Digite o nome do novo contato: ')
                endereco = input('Digite o endereco do novo contato: ')
                email = input('Digite o email do novo contato: ')
                telefones = input('Digite o numero de telefones do novo contato (N telefones com "+" entre eles): ')
                contato2 = "5_" + nome +"_"+ endereco +"_"+ email +"_"+ telefones + "\n"
                
                print("Msg que sera mandada para o server: " + contato2)
                sock.sendto(contato2.encode(),(HOST, PORT)) #enviando para o servidor
                
                data = ''
                data = sock.recv(1024).decode()

                if len(data) == 1:
                    data = sock.recv(1024).decode()

                print("Mensagem recebida do servidor:", data)
                data = ''
            pass
        elif opcao == 4: #DELETE
            print("\REMOVER CONTATO\n")
            nome = '' 
            nome = input('Digite o nome a ser removido: ')
            contato = "4_"+ nome + "\n"
            sock.sendto(contato.encode(),(HOST, PORT)) #enviando para o servidor
            data = ''
            data = sock.recv(1024)

            if len(data) == 1:
                data = sock.recv(1024).decode()
            print("Mensagem recebida do servidor:", data)
            data = ''
            pass
        elif opcao == 0:
            sock.sendto("0\n".encode(),(HOST, PORT))
            print("Encerrou a conexao com o server!")
            sock.close()
            sair = False
            pass
        else:
            print("\nEste número não está nas alternativas, tente novamente :D.")
        
        if len(data) == 1:
            data = sock.recv(1024).decode()
            data = ""
#-----------------------------------------------------
if __name__ == '__main__':
    main()
