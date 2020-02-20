Para utilizar este template siga o tutorial disponível em: https://biblioteca.ufc.br/wp-content/uploads/2015/09/tutorial-sharelatex.pdf

# Útimas alterações
03-07-2017              
    -Contagem de tabelas corrigida;
    -Dois pontos após fonte de figuras e tabelas;       
    -Inclusão do departamento na capa do trabalho;      
    -As equações foram alocadas completamente as esquerda. 
04-07-2017
    -inclusão de pdf em apêndice;
    -inclusão de pdf em anexo.
06-07-2017
    -espaçamento dos títulos de figuras, tabelas e quadros foram alterados de 1.5 para espaçamento simples (1.0);
    -Margens dos títulos das figuras ajustadas para ficar do tamanho da figura;
    -Margens dos títulos das tabelas ajustados para ficar do tamanho da tabela;
    -Quadro circunscrito de figuras retirados exceto, figuras de resultados.
    -espaçamento entre linhas ajustado para espaçamento simples nos títulos e legendas de figuras e tabelas;
10-07-2017
    -Elaboração de textos explicativos sobre figuras e equações;
    -Pasta renomeadas para ficar na ordem de pre, textual e pós;  
12-07-2017
    -O nome da pasta das referência estava errado. Isso fazia aparecer um ponto de interrogação nas citações. Isso já foi corrigido.
14-07-2017
    -Espaçamento corrigido entre o texto de identificação do trabalho e o orientador.
18-09-2017
    -Nome da LISTA DE ILUSTRAÇÕES alterado para LISTA DE FIGURAS
15-01-2018
    -Alteração do ano de 2017 para 2018
20-02-2018
    -Alteração do nome "Coorientador" de acordo com a nova norma ortográfica
24-02-2018
    -Inclusão de um texto chamando a atenção para o usuário configurar a opção referente ao nível do trabalho acadêmico que está sendo desenvolvido (tcc de graduação, trabalho de especialização, dissertação de mestrado ou tese de doutorado) nas primeiras opções do arquivo "documento.tex"
22-03-2018
    -Atualização dos e-mails para dúvidas e sugestões;
21-11-2018
    -Adicionada opção para alterar a fonte de todo o texto de Times New Roman para Arial. Basta descomentar as linhas 80 e 81 do arquivo "preambulo.tex" dentro da pasta "lib".
    -Nota de esclarecimento quanto a limitação da geração do referencial bibliográfico. 
09-01-2019
    -Acrescentado comentário explicando com deixar as equações centralizadas na linas 59 do arquivo "documento"
23-01-2019
    -Correção de erro de compilação na linha 60 do arquivo documentos. 
    -Nota de esclarecimento de como utilizar siglas.
07-06-2019
    -Atualização de contato para dúvidas e sugestões.
23-09-2019
    -Alteração do ano de 2018 para 2019. Atualização de tutorial ficha catalográfica para o Overleaf.
    
# O que é?

O **ufctex** é um projeto adaptado do [abnTeX2] da Associação Brasileira de normas técnicas [ueceTeX] da Universidade Estadual do Ceará. Essa versão, foi criada para o desenvolvimento de trabalhos acadêmicos de acordo com as normas da Universidade Federal do Ceará. Este template deve ser utilizado online de qualquer computador ou sistema operacional sem a necessidade de instalação e foi disponibilizada no ShareLaTex e no OverLeaf. Entretanto, é possível baixar o template e trabalhar offline também. 

Espera-se que o projeto seja um modelo de trabalho acadêmico que implemente todas as exigências das normas da ABNT sem a necessidade de se preocupar com o estilo ou formatação do documento. Entretanto, a geração de referências bibliográficas automática apresenta limitações quanto a formatação exigida pela biblioteca da UFC. E devem ser ajustadas manualmente estando sujeitas a revisão do bibliotecário.

### Modelos Disponíveis

**Trabalhos Acadêmicos**

 - Trabalho de Conclusão de Curso de Graduação
 - Trabalho de Conclusão de Curso de Especialização
 - Dissertação de Mestrado Acadêmico e Profissional
 - Tese de Doutorado
 
**Qualificações**

 - Qualificação para Mestrado Acadêmico e Profissional

# Limitações
 
 O modelo atual possui algumas limitações que podem ser corrigidas ou implementadas em alguma versão futura. São elas:
 
  - O modelo permite a participação de somente um co-orientador
  - A folha de aprovação da Dissertação suporta no máximo 5 pessoas (Orientador, Co-orientador e 3 membros externos)
  - A folha de aprovação da Tese suporta no máximo 6 pessoas (Orientador, Co-orientador e 4 membros externos)
  - As referências possuem muitas variações, portanto, o autor deve está atento se o arquivo gerado corresponde ao esperado.
  
# Dicas
Veja a seguir como inserir alguns elementos no seu texto.

### Como inserir uma Tabela
```tex
\begin{table}[h!]	
	\centering
	\Caption{\label{tab:label_da_tabela} Legenda da Tabela}
	\UFCtab{}{
		\begin{tabular}{ccll}
			\toprule
	    		Quisque & pharetra & tempus & vulputate \\
			\midrule \midrule
				E1 & Complete coverage & Both splice sites \\
				E2 & Complete coverage & Both splice sites \\
				E3 & Partial coverage & Both splice sites & Both \\
				E4 & Partial coverage & One splice site & Both \\
				E5 & Complete or coverage & No splice & Both \\
				E6 & No coverage & No splice sites\\
			\bottomrule
		\end{tabular}
	}{
		\Fonte{Elaborado pelo autor}
    }
\end{table}
```

### Como inserir um Quadro
```tex
\begin{quadro}[h!]	
	\centering
	\Caption{\label{qua:label_do_quadro} Legenda do Quadro}
	\UFCqua{}{
		\begin{tabular}{|c|c|}
			\hline
			Quisque & pharetra \\
			\hline
			E1 & Complete coverage  \\
			\hline
			E2 & Complete coverage \\
			\hline
		\end{tabular}
	}{
		\Fonte{Elaborado pelo autor}
	}
\end{quadro}
```

### Como inserir uma figura
```tex
\begin{figure}[h!]
	\centering
	\Caption{\label{fig:label_da_figura} Legenda da Figura}	
	\UFCfig{}{
	    \includegraphics[width=8cm]{figuras/figura-1}
	}{
	    \Fonte{Elaborado pelo autor}
	}	
\end{figure}
```

### Como inserir uma alínea
```tex
\begin{alineas}
	\item Lorem ipsum dolor sit amet;
    \item Praesent vitae nulla varius;
	\item Praesent quis erat eleifend;
	\item Mauris facilisis odio eu:
	\begin{subalineas}
		\item Integer non lacinia magna;
		\item Proin mattis placerat risus.
	\end{subalineas}
\end{alineas}
```

### Como criar Capítulos
```tex
\chapter{Fundamentação Teórica}
\label{cap:fundamentacao-teorica}
```

### Como criar Seções
```tex
% Seções Secundárias
\section{Objetivo Geral 2}
\label{sec:objetivo-geral-2}

% Seções Terciárias
\subsection{Objetivo Geral 3}
\label{sec:objetivo-geral-3}

% Seções Quaternárias
\subsubsection{Objetivo Geral 4}
\label{sec:objetivo-geral-4}

% Seções Quinárias
\subsubsubsection{Objetivo Geral 5}
\label{sec:objetivo-geral-5}
```

### Como inserir um algoritmo
```tex
\begin{algorithm}[h!]
	\SetSpacedAlgorithm
	\caption{\label{alg:algoritmo_de_colonica_de_formigas}Algoritmo de Otimização por Colônia de Formiga}
	\Entrada{Entrada do Algoritmo}
	\Saida{Saida do Algoritmo}
	\Inicio{
		Atribua os valores dos parâmetros\;
		Inicialize as trilhas de feromônios\;
		\Enqto{não atingir o critério de parada}{
			\Para{cada formiga}{
				Construa as Soluções\;
			}
			Aplique Busca Local (Opcional)\;
			Atualize o Feromônio\;
		}	
	}
\end{algorithm}
```

### Como inserir referências

@article{article,
  author  = {Peter Adams}, 
  title   = {The title of the work},
  journal = {The name of the journal},
  year    = 1993,
  number  = 2,
  pages   = {201-213},
  month   = 7,
  note    = {An optional note}, 
  volume  = 4
}

@book{book,
  author    = {Peter Babington}, 
  title     = {The title of the work},
  publisher = {The name of the publisher},
  year      = 1993,
  volume    = 4,
  series    = 10,
  address   = {The address},
  edition   = 3,
  month     = 7,
  note      = {An optional note},
  isbn      = {3257227892}
}

@booklet{booklet,
  title        = {The title of the work},
  author       = {Peter Caxton}, 
  howpublished = {How it was published},
  address      = {The address of the publisher},
  month        = 7,
  year         = 1993,
  note         = {An optional note}
}

@conference{conference,
  author       = {Peter Draper}, 
  title        = {The title of the work},
  booktitle    = {The title of the book},
  year         = 1993,
  editor       = {The editor},
  volume       = 4,
  series       = 5,
  pages        = 213,
  address      = {The address of the publisher},
  month        = 7,
  organization = {The organization},
  publisher    = {The publisher},
  note         = {An optional note}  
}

@inbook{inbook,
  author       = {Peter Eston}, 
  title        = {The title of the work},
  chapter      = 8,
  pages        = {201-213},
  publisher    = {The name of the publisher},
  year         = 1993,
  volume       = 4,
  series       = 5,
  address      = {The address of the publisher},
  edition      = 3,
  month        = 7,
  note         = {An optional note}
}

@incollection{incollection,
  author       = {Peter Farindon}, 
  title        = {The title of the work},
  booktitle    = {The title of the book},
  publisher    = {The name of the publisher},
  year         = 1993,
  editor       = {The editor},
  volume       = 4,
  series       = 5,
  chapter      = 8,
  pages        = {201-213},
  address      = {The address of the publisher},
  edition      = 3,
  month        = 7,
  note         = {An optional note}
}


@manual{manual,
  title        = {The title of the work},
  author       = {Peter Gainsford}, 
  organization = {The organization},
  address      = {The address of the publisher},
  edition      = 3,
  month        = 7,
  year         = 1993,
  note         = {An optional note}
}

@mastersthesis{mastersthesis,
  author       = {Peter Harwood}, 
  title        = {The title of the work},
  school       = {The school where the thesis was written},
  year         = 1993,
  address      = {The address of the publisher},
  month        = 7,
  note         = {An optional note}
}

@misc{misc,
  author       = {Peter Isley}, 
  title        = {The title of the work},
  howpublished = {How it was published},
  month        = 7,
  year         = 1993,
  note         = {An optional note}
}

@phdthesis{phdthesis,
  author       = {Peter Joslin}, 
  title        = {The title of the work},
  school       = {The school where the thesis was written},
  year         = 1993,
  address      = {The address of the publisher},
  month        = 7,
  note         = {An optional note}
}

@proceedings{proceedings,
  title        = {The title of the work},
  year         = 1993,
  editor       = {Peter Kidwelly},
  volume       = 4,
  series       = 5,
  address      = {The address of the publisher},
  month        = 7,
  organization = {The organization},
  publisher    = {The name of the publisher},
  note         = {An optional note}
}

@techreport{techreport,
  author       = {Peter Lambert}, 
  title        = {The title of the work},
  institution  = {The institution that published},
  year         = 1993,
  number       = 2,
  address      = {The address of the publisher},
  month        = 7,
  note         = {An optional note}
}

@unpublished{unpublished,
  author       = {Peter Marcheford}, 
  title        = {The title of the work},
  note         = {An optional note},
  month        = 7,
  year         = 1993
}


# Atenção

O ufcteX é fornecido gratuitamente e sem garantias e pode ser redistribuído livremente para fins acadêmicos. 

# Agradecimentos

![alt tag](http://www.goes.uece.br/style/images/logo_goes.png)

Grupo de Otimização em Engenharia de Software



[Por Onde Comecar]:https://code.google.com/p/abntex2/wiki/PorOndeComecar

Projeto original da UECE: [http://www.goes.uece.br]:http://www.goes.uece.br
[http://www.goes.uece.br]
[abnTeX2]:https://code.google.com/p/abntex2/
[http://miktex.org/download]:http://miktex.org/download
[http://texstudio.sourceforge.net/]:http://texstudio.sourceforge.net/


