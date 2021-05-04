 buildMinHeap(assentos, fileiras);
  return total(assentos,fileiras,pessoas);


 }

float total(int* assentos, int fileiras, int pessoas){
    float lucro = 0;
    while(pessoas > 0){
      int resto = FP_inicio(assentos, fileiras);
      fileiras = FP_remover_minimo(assentos, fileiras);
     
      while(resto > 0 && pessoas > 0){
        lucro += 100 + (float)100 / resto;
        resto--;
        pessoas--;
      }
    }
  return lucro;
}