int a = 2, b = 3, c = 4, d = 5;
int resultado = 0;
void setup() {
  // put your setup code here, to run once:
  
//Leds  
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
//botones - entradas
  pinMode(a, INPUT);
  pinMode(b, INPUT);
  pinMode(c, INPUT);
  pinMode(d, INPUT);

//botones - bus de contol
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
}

void suma()
{
  if ((digitalRead(a) ^ digitalRead(b)))
    digitalWrite(9, HIGH);
  else
    digitalWrite(9, LOW);

  if ((digitalRead(a) && digitalRead(b)) ^ (digitalRead(c) ^ digitalRead(d)))
    digitalWrite(10, HIGH);
  else
    digitalWrite(10, LOW);

    if ((digitalRead(a) && digitalRead(b)) && (digitalRead(c) ^ digitalRead(d)))
    digitalWrite(11, HIGH);
  else
    digitalWrite(11, LOW);

  if ((digitalRead(c) && digitalRead(d)))
    digitalWrite(11, HIGH);
  else
    digitalWrite(11, LOW);
}

void resta()
{
 if ((digitalRead(a) == HIGH && digitalRead(b) == HIGH) && digitalRead(c) == LOW)
  {
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
  }
  else
  {
    // Realizar la resta normalmente
    if ((digitalRead(a) == HIGH && digitalRead(b) == LOW) || (digitalRead(a) == LOW && digitalRead(b) == HIGH))
      digitalWrite(9, HIGH);
    else
      digitalWrite(9, LOW);

    if ((digitalRead(c) == HIGH && digitalRead(d) == LOW) || (digitalRead(c) == LOW && digitalRead(d) == HIGH))
      digitalWrite(10, HIGH);
    else
      digitalWrite(10, LOW);

    if ((digitalRead(c) == HIGH && digitalRead(d) == LOW && digitalRead(a) == LOW && digitalRead(b) == HIGH) || (digitalRead(c) == LOW && digitalRead(d) == HIGH && digitalRead(a) == LOW && digitalRead(b) == HIGH))
      digitalWrite(11, HIGH);
    else
      digitalWrite(11, LOW);
  }
}

void multiplicacion() {
  if (digitalRead(a) != digitalRead(b)) {
  digitalWrite(9, LOW);
} else {
  digitalWrite(9, HIGH);
}

// Salida LED10
if ((digitalRead(a) && digitalRead(b)) == (digitalRead(c) ^ digitalRead(d))) {
  digitalWrite(10, LOW);
} else {
  digitalWrite(10, HIGH);
}

// Salida LED11 (modificado)
if ((digitalRead(a) && digitalRead(d)) || (digitalRead(c) && digitalRead(d))) {
  digitalWrite(11, LOW);
} else {
  digitalWrite(11, HIGH);
}

// Salida LED12
if (digitalRead(c) && digitalRead(d)) {
  digitalWrite(12, HIGH);
} else {
  digitalWrite(12, LOW);
}
}

void division()
{
  //Auftteilung (División)
  if(!digitalRead(b) && !digitalRead(a)){
      //ERROR
      digitalWrite(12,HIGH);
      delay(1000);
      digitalWrite(12,LOW);      
      delay(1000);
  }
  else if(!digitalRead(a)&&!digitalRead(b)){
       //Cero bits
      //Cociente
      digitalWrite(11,LOW);
      digitalWrite(12,LOW);
    
      //Residuo
      digitalWrite(9,LOW);
      digitalWrite(10,LOW);    
     }
  
  else if(digitalRead(a)&&digitalRead(c)){
      //1
      //Cociente
      digitalWrite(11,HIGH);  
  }
  
  else if(digitalRead(a)&&digitalRead(b)&&!digitalRead(c)&&digitalRead(d))
  {//1.decimal 
      //Cociente
      digitalWrite(11,HIGH);    

      //Residuo
      digitalWrite(9,HIGH);
  }
  
  else if(!digitalRead(a)&&digitalRead(b)&&digitalRead(c)&&!digitalRead(d)){
    //Mismo
    digitalWrite(12,HIGH);
  }
  
  else if(digitalRead(a)&&digitalRead(b)&&digitalRead(c)&&!digitalRead(d)){
    //Mismo 
    digitalWrite(12,HIGH);
    digitalWrite(11,HIGH);
  }
  
  else if(digitalRead(a)&&!digitalRead(b)&&digitalRead(c)&&digitalRead(d)){//0.decimal 
   	  //Residuo 
      digitalWrite(10,HIGH);    

  }
}


void And(){
  if (digitalRead(a) && digitalRead(b) && digitalRead(c) && digitalRead(d))
    digitalWrite(9, HIGH);
  else
    digitalWrite(9, LOW);

}

void Or(){
  if (digitalRead(a) || digitalRead(b) || digitalRead(c) || digitalRead(d))
    digitalWrite(9, HIGH);
  else
    digitalWrite(9, LOW);
}

void Xor(){
  if (digitalRead(a) ^ digitalRead(b) ^ digitalRead(c) ^ digitalRead(d))
    digitalWrite(9, HIGH);
  else
    digitalWrite(9, LOW);
}



void loop() {  

  if ((!digitalRead(6) && !digitalRead(7) && digitalRead(8)))
  {
    suma();
  }

  if ((!digitalRead(6) && digitalRead(7) && !digitalRead(8)))
  {
    resta();
  }

  if ((!digitalRead(6) && digitalRead(7) && digitalRead(8)))
  {
    multiplicacion();
  }

  if ((digitalRead(6) && !digitalRead(7) && !digitalRead(8)))
  {
    division();
  }

  if ((digitalRead(6) && !digitalRead(7) && digitalRead(8)))
  {
    And();
  }

  if ((digitalRead(6) && digitalRead(7) && !digitalRead(8)))
  {
    Or();
  }

  if ((digitalRead(6) && digitalRead(7) && digitalRead(8)))
  {
    Xor();
  }
}
