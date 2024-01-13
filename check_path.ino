void check_path() {
 if (ary[1] == 1 && ary[2] == 1 && ary[3] == 1 && ary[4] == 1 && ary[5] == 1 && ary[6] == 1 && ary[7] == 1 && ary[8] == 1) {
   
    if(state!=1){go_Hstop(50,50);}
    else{go_left();}
     state=1;
  }
  else if ( ary[6] == 1 && ary[7] == 1 && ary[8] == 1) {
  if(state!=2){go_Hstop(200,200);}
    else{go_left();}
  state=2;
  //  go_left();
  }
  else if (ary[1] == 1 && ary[2] == 1 && ary[3] == 1 ) {
   if(state!=3){go_Hstop(200,200);}
    else{go_right();}
   state=3;
   // 
  }
  else if (ary[1] == 0 && ary[2] == 0 && ary[3] == 0 && ary[4] == 0 && ary[5] == 0 && ary[6] == 0 && ary[7] == 0 && ary[8] == 0) {
    
if(state!=4){go_Hstop(200,200);}
    else{go_back();}
   state=4;
  }
  
  else {
   state=5;
      if(state!=5){go_forword(150,150);}
      else{go_forword(120,120);}
  }



}
void go_left() {
  Serial.println("go_left");
  analogWrite(ena, 200);
  analogWrite(enb, 200);

  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorForward, HIGH);
  digitalWrite(RightMotorBackward, LOW);
 delay(10);
  analogWrite(ena, 130);
  analogWrite(enb, 130);
  
  delay(900);
   analogWrite(ena, 0);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  digitalWrite(RightMotorBackward, LOW);
  delay(800);
  while(digitalRead(pin4 )==0){delay(10);} 
  
  //delay(1100);
  analogWrite(ena, 0);
  analogWrite(enb, 0);
}
void go_right() {
  Serial.println("go_right");
  analogWrite(ena, 200);
  analogWrite(enb, 200);

  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorForward, HIGH);
  digitalWrite(RightMotorBackward, LOW);
 delay(10);
  analogWrite(ena, 130);
  analogWrite(enb, 130);
  
  delay(800);
   analogWrite(enb, 0);
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorForward, LOW);
  digitalWrite(RightMotorBackward, HIGH);
  delay(800);
  while(digitalRead(pin7)==0){delay(10);}
  //delay(900);
  analogWrite(ena, 80);
  analogWrite(enb, 80);
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorForward, HIGH);
  digitalWrite(RightMotorBackward, LOW);
}

void go_forword(int a,int b) {
  Serial.println("go_forword");
int cal_err=ary[1]*W[1]+ary[2]*W[2]+ary[3]*W[3]+ary[4]*W[4]
           +ary[5]*W[5]+ary[6]*W[6]+ary[7]*W[7]+ary[8]*W[8];
//cal_err=0;
 Serial.print(a+cal_err); Serial.print(",");Serial.print(b-cal_err);
  analogWrite(ena, a+cal_err);
  analogWrite(enb, b-cal_err);
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorForward, HIGH);
  digitalWrite(RightMotorBackward, LOW);





}
void go_back() {
  Serial.println("go_back");
analogWrite(ena, 0);
  analogWrite(enb, 0);
  delay(300);
  analogWrite(ena, 130);
  analogWrite(enb, 130);

  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorForward, HIGH);
  digitalWrite(RightMotorBackward, LOW);
 delay(300);

  analogWrite(ena, 0);
  analogWrite(enb, 0);
   delay(200);


  analogWrite(ena, 120);
  analogWrite(enb, 150);

  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorForward, LOW);
  digitalWrite(RightMotorBackward, HIGH);
  delay(900);
  analogWrite(ena, 120);
  analogWrite(enb, 120);
while(digitalRead(pin2)==0){delay(10);}
  //delay(900);
   analogWrite(ena, 80);
  analogWrite(enb, 80);
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorForward, HIGH);
  digitalWrite(RightMotorBackward, LOW);
 
  
}
void go_Hstop(int a,int b) {
  Serial.println("go_stop");
  analogWrite(ena, a);
  analogWrite(enb, b);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorForward, LOW);
  digitalWrite(RightMotorBackward, HIGH);
  delay(100);
  analogWrite(ena, 0);
  analogWrite(enb, 0);
}
void go_stop() {
  Serial.println("go_stop");
  analogWrite(ena, 0);
  analogWrite(enb, 0);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);
}
