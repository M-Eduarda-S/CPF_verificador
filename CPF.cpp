/* Trabalho em grupo da universidade - Nomes dos intregrantes: Nilson Hoffmann Neto, Maria Eduarda Santos, Leonardo dos Santos Cardoso, Camilly Akimi Takahashi, Fernando Nobre Kalil. */
#include <iostream>
using namespace std;

int main() {
  setlocale(LC_ALL, "Portuguese"); // Permite acentuação.

  int cpf, n1, n2, n3, n4, n5, n6, n7, n8, n9, peso;
  int d1, d2, soma, resto; // soma = soma dos dígitos e resto = resto da divisão.

  cout << "Digite os primeiros 8 a 9 dígitos do CPF: ";
  cin >> cpf;

  n9 = cpf % 10; // 9º dígito é igual ao resto da divisão do CPF por 10.
  cpf = cpf / 10; // Dividindo o CPF por 10 para pegar os próximos 8 dígitos.
  n8 = cpf % 10;
  cpf = cpf / 10;
  n7 = cpf % 10;
  cpf = cpf / 10;
  n6 = cpf % 10;
  cpf = cpf / 10;
  n5 = cpf % 10;
  cpf = cpf / 10;
  n4 = cpf % 10;
  cpf = cpf / 10;
  n3 = cpf % 10;
  cpf = cpf / 10;
  n2 = cpf % 10;
  cpf = cpf / 10;
  n1 = cpf % 10;
  cpf = cpf / 10;

  // Cálculo do primeiro dígito verificador (d1).
  peso = 10; // Peso começa com 10.
  soma = n1 * 10 + n2 * 9 + n3 * 8 + n4 * 7 + n5 * 6 + n6 * 5 + n7 * 4 + n8 * 3 + n9 * 2; // Soma dos dígitos multiplicados pelo peso.
  resto = soma % 11; // Resto da divisão da soma por 11.

  // Verificação do primeiro dígito verificador.
  if (resto < 2) {
    d1 = 0;
  } else {
    d1 = 11 - resto;
  }

  // Incorpora o primeiro dígito verificador no cálculo do segundo dígito.
  peso = 11;  // Peso para o segundo dígito.
  soma = n1 * 11 + n2 * 10 + n3 * 9 + n4 * 8 + n5 * 7 + n6 * 6 + n7 * 5 + n8 * 4 + n9 * 3 + d1 * 2;
  resto = soma % 11;

  if (resto < 2) {
    d2 = 0;
  } else {
    d2 = 11 - resto;
  }

  // Verificação se todos os dígitos são iguais.
  if (n1 == n2 && n2 == n3 && n3 == n4 && n4 == n5 && n5 == n6 && n6 == n7 && n7 == n8 && n8 == n9) {
    cout << endl << "O CPF é inválido, pois todos os dígitos são iguais." << endl;
  } else { // Exibe o CPF completo com os dígitos verificadores.
    cout << endl << "CPF completo: " << n1 << n2 << n3 << "." << n4 << n5 << n6<< "." << n7 << n8 << n9 << "-" << d1 << d2 << endl;
  }

  return 0;
}
