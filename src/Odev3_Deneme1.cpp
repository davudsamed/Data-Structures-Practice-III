/**
 * @description Ýkili arama aðaçlarý üzerinde eleman ekleme, eleman silme ve soy sayýsýný bulma gibi çeþitli iþlemler yapýlýyor.
 * @course  Örgün Eðitim 2.Sýnýf
 * @assignment  3
 * @date  15.12.2019
 * @author Davud Samed Tombul(b171210007@sakarya.edu.tr)
 **/
#include "BinarySearchTree.h"
#include<iostream>

using namespace std;

int main() {
	BinarySearchTree* nesne = new BinarySearchTree; //Heap bellek bölgesinde BinarySearchTree adlý sýnýftan nesne oluþturuluyor.
	nesne->basla(); //BinarySearchTree class'ýndan oluþturulan nesnenin basla adlý parametresiz fonksiyonu çaðýrýlýyor.
	return system("PAUSE");
}