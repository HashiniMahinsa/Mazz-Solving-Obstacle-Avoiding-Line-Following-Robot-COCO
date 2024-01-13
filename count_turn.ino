void count_path() {
  int t1=digitalRead(53);
  if (t1 == 1 && countlock == 0) {
    delay(20);
    if (digitalRead(53) == 1 && countlock == 0) {
      countpath++;
      countlock = 1;
      String sendd="stop "+String(countpath)+" "+String(t1);
     
      Serial1.println(sendd);
      Serial.println(countpath);
   if(to_go!=countpath){  skip_forw();}
   
    }
  }
  if (digitalRead(irL1) == 0 && countlock == 1) {
    countlock = 0;
  }
}




void only_forw() {

  go_forword(120, 120);


}

void skip_forw() {
  delay(1000);

}


void go_left_fin() {
  Serial1.println("go_left_fn");


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
