
/**
  * Algoritmo: Troco
  * Tipo: 	   Guloso
  * Data: 12/2/2018
  *
  */
  
  /** 			Algoritmos Gulos
    *
    * Sempre escolhe a alternativa que parece mais promissora naquele instante
    * NUNCA reconsidera uma decis�o
    * Uma escolha que foi feita nunca � revisada
    * N�o h� baktrancking (um passo atr�s)
    * A escolha � feita de acordo com um criterio guloso - decis�o localmente �tima
    * Nem sempre d�o decis�es �timas
    */
    
  /**
    * 75 / 100 = 0
    * 75 % 100 = 75
    *
    * 75 / 50  = 1
    * 75 % 50  = 25
    *
    * 25 / 25  = 1
    * 25 % 25  = 0
    *
    */
      
  
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void trocoMinimo(int *moedas, int quantidade, int troco) {

	int count, quantidadeDeMoeda;
	
	count = quantidadeDeMoeda = 0;
	
	do {
		quantidadeDeMoeda = troco / moedas[count]; 						//guarda a quantidade de Moedas
		troco %= moedas[count];											// guarda o resto, novo troco
		
		if (quantidadeDeMoeda > 0) {
			printf("%d c�dula(s) de R$ %d.00 reais\n", quantidadeDeMoeda, moedas[count]);
		}
		
		count++;
	} while (count < quantidade); 
		
}




int main() {
	setlocale(LC_ALL, "portuguese");
	
	int moedas[6] = {100, 50, 25, 20, 5, 1};  		   //Me retorna a solu��o �tima
	/*int moedas[6] = {100, 50, 20, 5, 25, 1};*/       //N�o me retorna a solu��o �tima
	trocoMinimo(moedas, 6, 130);
	

	
	
	return 0;
}
