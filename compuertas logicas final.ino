//emtradas
const int s1 = A1;
const int s2 = A2;
const int s3 = A3;
const int s4 = A4;
const int s5 = 2;
const int s6 = 3;
const int s7 = 4;

//resultado
int sumafinal = 0;
int resultado;
int decimalNumber;
int vector1[2];
int vector2[2];
int vectorR[2];
// salidas
const int A = 7;
const int B = 8;
const int C = 9;
const int D = 10;
const int E = 11;
const int F = 12;
const int G = 13;

const int Digito1 = 5;
const int Digito2 = 6;
//estados
int EstadosA = 0;
int EstadosB = 0;
int EstadosC = 0;
int EstadosD = 0;
int EstadosE = 0;
int EstadosF = 0;
int EstadosG = 0;
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);

  pinMode(s1, INPUT);
  pinMode(s2, INPUT);
  pinMode(s3, INPUT);
  pinMode(s4, INPUT);
  pinMode(s5, INPUT);
  pinMode(s6, INPUT);
  pinMode(s7, INPUT);

  pinMode(Digito1, OUTPUT);
  pinMode(Digito2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // put your main code here, to run repeatedly:
  EstadosA = digitalRead(s1);
  EstadosB = digitalRead(s2);
  EstadosC = digitalRead(s3);
  EstadosD = digitalRead(s4);
  EstadosE = digitalRead(s5);
  EstadosF = digitalRead(s6);
  EstadosG = digitalRead(s7);
  //suma

  vector1[0] = EstadosB;
  vector1[1] = EstadosA;
  vector2[0] = EstadosD;
  vector2[1] = EstadosC;

  int multi = 0;


  //compuerta logica and jala
  if (!EstadosE && !EstadosF && !EstadosG) {
    if ((vector1[1] && vector2[1])) {
      int numero1 = 0; int numero2 = 0; int multi = 0;
      numero1 = vector1[1];
      numero2 = vector2[1];
      multi = numero1 * numero2;
      retorno(multi);
    }
    if ((vector1[0] && vector2[0])) {
      int numero1 = 0; int numero2 = 0; int multi = 0;
      numero1 = vector1[0];
      numero2 = vector2[0];
      multi = numero1 * numero2;
      retorno(multi);
    } else if (!EstadosA && !EstadosB && !EstadosC && !EstadosD) {
      retorno(multi);
    }
  }

  //compuerta logica OR jala
  if (!EstadosE && !EstadosF && EstadosG) {
    int numero1 = 0; int numero2 = 0; int multi = 0;

    if (EstadosA || EstadosC) {
      numero1 = vector1[1];
      numero2 = vector2[1];
      multi = numero1 + numero2;
      if (multi == 2) {
        multi = 1;
        retorno(multi);
      } else {
        retorno(multi);
      }
    } else if (EstadosB || EstadosD) {
      numero1 = vector1[0];
      numero2 = vector2[0];
      multi = numero1 + numero2;
      if (multi == 2) {
        multi = 1;
        retorno(multi);
      } else {
        retorno(multi);
      }
    } else if (!EstadosA && !EstadosB && !EstadosC && !EstadosD) {
      multi = 0 ;
      retorno(multi);
    }
  }

  //compuerta logica xor
  if (!EstadosE && EstadosF && !EstadosG) {
    int numero1 = 0; int numero2 = 0; int multi = 0;
    if (EstadosA || EstadosC) {
      numero1 = vector1[1];
      numero2 = vector2[1];
      multi = numero1 + numero2;
      if (multi == 2) {
        multi = 0;
        retorno(multi);
      } else {
        retorno(multi);
      }
    } else if (EstadosB || EstadosD) {
      numero1 = vector1[0];
      numero2 = vector2[0];
      multi = numero1 + numero2;
      if (multi == 2) {
        multi = 0;
        retorno(multi);
      } else {
        retorno(multi);
      }
    } else if (!EstadosA && !EstadosB && !EstadosC && !EstadosD) {
      multi = 0 ;
      retorno(multi);
    }
  
    //int numero1 = 0; int numero2 = 0; int multi = 0;
    //Serial.println("entrooooooooooo en el xorrr");
     /*if(EstadosA){
      multi = 1; 
      retorno(multi); 
     }else if (EstadosC){
      multi = 1; 
      retorno(multi); 
     }else if(EstadosB){
       multi = 1; 
      retorno(multi); 
     } else if(EstadosD){
      multi = 1; 
      retorno(multi);
     }else if(EstadosA || EstadosC){
      multi = 0;  
      retorno(multi); 
     }else if(EstadosB && EstadosD){
      multi= 0; 
      retorno(multi);
     }else if(!EstadosA && !EstadosB && !EstadosC && !EstadosD){
        retorno(0);
     }*/
      /*if(EstadosA && EstadosC){
      multi = 0;  
      retorno(multi); 
     }else if(EstadosB && EstadosD){
      multi= 0; 
      retorno(multi);
     }else if(!EstadosA || EstadosC){
      multi = 1;  
      retorno(multi);
      }else if(!EstadosA || !EstadosC){
      multi= 0; 
      retorno(multi);
      }
     else if(!EstadosA || !EstadosB ){
        retorno(0);
     }else if(!EstadosC || !EstadosD){
      retorno(0);
     }*/
  }

  //not
  if (!EstadosE && EstadosF && EstadosG) {
    if (!EstadosA || !EstadosC) {
      multi = 1
      retorno(multi);
    }
    if (EstadosA  || EstadosC) {
     multi=0;
     retorno(multi);
    } 
  }
  //suma
  if (EstadosE && !EstadosF && !EstadosG) {
    retorno(0);
    sumafinal = 0;
    Serial.println("entro en la suma ");
    int numero1 = convertBinaryToDecimal(vector1);
    int numero2 = convertBinaryToDecimal(vector2);
    int sumafinal = numero1 + numero2;
    retorno(sumafinal);
    //resta
  } else if (EstadosE && !EstadosF && EstadosG) {
    sumafinal = 0;
    Serial.println("entro en la resta ");
    int numero1 = convertBinaryToDecimal(vector1);
    int numero2 = convertBinaryToDecimal(vector2);
    int sumafinal = numero1 - numero2;
    retorno(sumafinal);
    //multiplicacion
  } else if (EstadosE && EstadosF && !EstadosG) {
    sumafinal = 0;
    Serial.println("entro en la multiplicacion ");
    int numero1 = convertBinaryToDecimal(vector1);
    int numero2 = convertBinaryToDecimal(vector2);
    int sumafinal = numero1 * numero2;
    retorno(sumafinal);
    //division
  } else if (EstadosE && EstadosF && EstadosG) {
    sumafinal = 0;
    Serial.println("entro en la division ");
    int numero1 = convertBinaryToDecimal(vector1);
    int numero2 = convertBinaryToDecimal(vector2);
    int sumafinal = numero1 / numero2;
    retorno(sumafinal);
  }
}

int convertBinaryToDecimal(int vector[]) {
  int suma = 0;

  for (int i = 0; i <= 1; i++) {
    if (vector[i] == 1 && i == 0) {
      suma = suma + 1;
    }
    if (vector[i] == 1 && i == 1) {
      suma = suma + 2;
    }
  }


  return suma;
}

int retorno(int numero) {

  switch (numero) {
    case 1:
      digitalWrite(5, 0);  // apaga el derecho
      digitalWrite(6, 1);  // enciende el izquierdo
      cero();
      delay(5);
      digitalWrite(5, 1);  // prende el derecho
      digitalWrite(6, 0);  // apaga el izquierdo
      uno();
      delay(5);
      break;
    case 2:
      digitalWrite(5, 0);  // apaga el derecho
      digitalWrite(6, 1);  // enciende el izquierdo
      cero();
      delay(5);
      digitalWrite(5, 1);  // prende el derecho
      digitalWrite(6, 0);  // apaga el izquierdo
      dos();
      delay(5);
      break;
    case 3:
      digitalWrite(5, 0);  // apaga el derecho
      digitalWrite(6, 1);  // enciende el izquierdo
      cero();
      delay(5);
      digitalWrite(5, 1);  // prende el derecho
      digitalWrite(6, 0);  // apaga el izquierdo
      tres();
      delay(5);
      break;
    case 4:
      digitalWrite(5, 0);  // apaga el derecho
      digitalWrite(6, 1);  // enciende el izquierdo
      cero();
      delay(5);
      digitalWrite(5, 1);  // prende el derecho
      digitalWrite(6, 0);  // apaga el izquierdo
      cuatro();
      delay(5);
      break;
    case 5:
      digitalWrite(5, 0);  // apaga el derecho
      digitalWrite(6, 1);  // enciende el izquierdo
      cero();
      delay(5);
      digitalWrite(5, 1);  // prende el derecho
      digitalWrite(6, 0);  // apaga el izquierdo
      cinco();
      delay(5);
      break;
    case 6:
      digitalWrite(5, 0);  // apaga el derecho
      digitalWrite(6, 1);  // enciende el izquierdo
      cero();
      delay(5);
      digitalWrite(5, 1);  // prende el derecho
      digitalWrite(6, 0);  // apaga el izquierdo
      seis();
      delay(5);
      break;
    case 7:
      digitalWrite(5, 0);  // apaga el derecho
      digitalWrite(6, 1);  // enciende el izquierdo
      cero();
      delay(5);
      digitalWrite(5, 1);  // prende el derecho
      digitalWrite(6, 0);  // apaga el izquierdo
      siete();
      delay(5);
      break;
    case 8:
      digitalWrite(5, 0);  // apaga el derecho
      digitalWrite(6, 1);  // enciende el izquierdo
      cero();
      delay(5);
      digitalWrite(5, 1);  // prende el derecho
      digitalWrite(6, 0);  // apaga el izquierdo
      ocho();
      delay(5);
      break;
    case 9:
      digitalWrite(5, 0);  // apaga el derecho
      digitalWrite(6, 1);  // enciende el izquierdo
      cero();
      delay(5);
      digitalWrite(5, 1);  // prende el derecho
      digitalWrite(6, 0);  // apaga el izquierdo
      nueve();
      delay(5);
      break;
    case 0:
      digitalWrite(5, 0);  // apaga el derecho
      digitalWrite(6, 1);  // enciende el izquierdo
      cero();
      delay(5);
      digitalWrite(5, 1);  // prende el derecho
      digitalWrite(6, 0);  // apaga el izquierdo
      cero();
      delay(5);
      break;
  }
}

void uno() {
  digitalWrite(7, 1);
  digitalWrite(8, 1);
  digitalWrite(9, 0);
  digitalWrite(10, 0);
  digitalWrite(11, 0);
  digitalWrite(12, 0);
  digitalWrite(13, 0);
}

void dos() {
  digitalWrite(7, 0);
  digitalWrite(8, 1);
  digitalWrite(9, 1);
  digitalWrite(10, 0);
  digitalWrite(11, 1);
  digitalWrite(12, 1);
  digitalWrite(13, 1);
}

void tres() {
  digitalWrite(7, 1);
  digitalWrite(8, 1);
  digitalWrite(9, 1);
  digitalWrite(10, 0);
  digitalWrite(11, 0);
  digitalWrite(12, 1);
  digitalWrite(13, 1);
}


void cuatro() {
  digitalWrite(7, 1);
  digitalWrite(8, 1);
  digitalWrite(9, 0);
  digitalWrite(10, 1);
  digitalWrite(11, 0);
  digitalWrite(12, 0);
  digitalWrite(13, 1);
}

void cinco() {
  digitalWrite(7, 1);
  digitalWrite(8, 0);
  digitalWrite(9, 1);
  digitalWrite(10, 1);
  digitalWrite(11, 0);
  digitalWrite(12, 1);
  digitalWrite(13, 1);
}

void seis() {
  digitalWrite(7, 1);
  digitalWrite(8, 0);
  digitalWrite(9, 1);
  digitalWrite(10, 1);
  digitalWrite(11, 1);
  digitalWrite(12, 1);
  digitalWrite(13, 1);
}

void siete() {
  digitalWrite(7, 1);
  digitalWrite(8, 1);
  digitalWrite(9, 1);
  digitalWrite(10, 0);
  digitalWrite(11, 0);
  digitalWrite(12, 0);
  digitalWrite(13, 0);
}

void ocho() {
  digitalWrite(7, 1);
  digitalWrite(8, 1);
  digitalWrite(9, 1);
  digitalWrite(10, 1);
  digitalWrite(11, 1);
  digitalWrite(12, 1);
  digitalWrite(13, 1);
}

void nueve() {
  digitalWrite(7, 1);
  digitalWrite(8, 1);
  digitalWrite(9, 1);
  digitalWrite(10, 1);
  digitalWrite(11, 0);
  digitalWrite(12, 1);
  digitalWrite(13, 1);
}
void cero() {
  digitalWrite(7, 1);
  digitalWrite(8, 1);
  digitalWrite(9, 1);
  digitalWrite(10, 1);
  digitalWrite(11, 1);
  digitalWrite(12, 1);
  digitalWrite(13, 0);
}