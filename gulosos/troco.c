
/**
  * Algoritmo: Troco
  * Tipo: 	   Guloso
  * Data: 12/2/2018
  *
  */
  
  /** 			Algoritmos Gulos
    *
    * Sempre escolhe a alternativa que parece mais promissora naquele instante
    * NUNCA reconsidera uma decisão
    * Uma escolha que foi feita nunca é revisada
    * Não há baktrancking (um passo atrás)
    * A escolha é feita de acordo com um criterio guloso - decisão localmente ótima
    * Nem sempre dão decisões ótimas
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
			printf("%d cédula(s) de R$ %d.00 reais\n", quantidadeDeMoeda, moedas[count]);
		}
		
		count++;
	} while (count < quantidade); 
		
}




int main() {
	setlocale(LC_ALL, "portuguese");
	
	int moedas[6] = {100, 50, 25, 20, 5, 1};  		   //Me retorna a solução ótima
	/*int moedas[6] = {100, 50, 20, 5, 25, 1};*/       //Não me retorna a solução ótima
	trocoMinimo(moedas, 6, 130);
	

	
	
	return 0;
}
