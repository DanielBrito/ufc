# Copyright 2015 gRPC authors.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
"""The Python implementation of the GRPC helloworld.Greeter client."""

from __future__ import print_function
import logging

import grpc

import helloworld_pb2
import helloworld_pb2_grpc


def run():
    # NOTE(gRPC Python Team): .close() is possible on a channel and should be
    # used in circumstances in which the with statement does not fit the needs
    # of the code.
    with grpc.insecure_channel('localhost:50051') as channel:
        stub = helloworld_pb2_grpc.GreeterStub(channel)
        
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
                nome = raw_input('Digite o nome do novo contato: ')
                endereco = raw_input('Digite o endereco do novo contato: ')
                email = raw_input('Digite o email do novo contato: ')
                while True:
                    aux_telefones = raw_input('Digite o telefone (ou deixe em branco para sair): ')
                    if len(aux_telefones) == 0:
                        break
                    if len(telefones) == 0:
                        telefones = aux_telefones
                    else:
                        telefones = telefones + "+" + aux_telefones
                contato = "1_" + nome +"_"+ endereco + "_"+ email + "_" + telefones
                #print("Mensagem que sera mandada para o server: " + contato)
                
                response = ''
                response = stub.AdicionarContato(helloworld_pb2.HelloRequest(name=contato))
                print("\nMensagem recebida do servidor:", response.message)
                pass
            elif opcao == 2:
                print("\nPROCURAR CONTATO\n")
                nome = '' 
                nome = raw_input('Digite o nome a ser procurado: ')
                contato = "2_"+ nome
                
                response = stub.ProcurarContato(helloworld_pb2.HelloRequest(name=contato))
                print("\nMensagem recebida do servidor:",response.message)
                pass
            elif opcao == 3: #Update contact
                print("\nATUALIZAR CONTATO\n")
                nome = '' 
                nome = raw_input('Digite o nome a ser atualizado: ')
                contato = "3_"+ nome
                
                response = stub.AtualizarContato(helloworld_pb2.HelloRequest(name=contato))
                print('\nMensagem recebida do servidor:' + response.message)

                if response.message == 'Nao encontrei nenhum contato':
                    print('')
                else:                    
                    contato2 = ''
                    print("\nDADOS NOVOS DO CONTATO\n")
                    nome = ''
                    endereco = ''
                    email = ''
                    telefones = ''
                    nome = raw_input('Digite o nome do novo contato: ')
                    endereco = raw_input('Digite o endereco do novo contato: ')
                    email = raw_input('Digite o email do novo contato: ')
                    while True:
                        aux_telefones = raw_input('Digite o telefone (ou deixe em branco para sair): ')
                        if len(aux_telefones) == 0:
                            break
                        if len(telefones) == 0:
                            telefones = aux_telefones
                        else:
                            telefones = telefones + "+" + aux_telefones
                    contato2 = "5_" + nome +"_"+ endereco +"_"+ email +"_"+ telefones
                    #print("Msg que sera mandada para o server: " + contato2)
                    
                    response2 = stub.AtualizarDadosContato(helloworld_pb2.HelloRequest(name=contato2))
                    print('\nMensagem recebida do servidor: ' + response2.message)
                pass
            elif opcao == 4: #DELETE
                print("\nDELETAR CONTATO\n")
                nome = '' 
                nome = raw_input('Digite o nome a ser removido: ')
                contato = "4_"+ nome
                response = stub.DeletarContato(helloworld_pb2.HelloRequest(name=contato))
                print('\nMensagem recebida do servidor: ' + response.message)
                pass
            elif opcao == 0:
                print("Encerrou a conexao com o server!")
                sair = False

if __name__ == '__main__':
    logging.basicConfig()
    run()