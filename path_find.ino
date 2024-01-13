int pin1=46,pin2=47,pin3=48,pin4=49,pin5=50,pin6=51,pin7=52,pin8=53;
int irR1=45,irL1=44;
int ary[9]={0,0,0,0,0,0,0,0,0};
int W[9]={0,+10,-10,-2,-1,1,2,10,20};
int led=13;
int irR=0,irL=0;
int ena = 7;//
int enb = 12;// 
const int LeftMotorForward = 11;
const int LeftMotorBackward = 10;
const int RightMotorForward = 8;
const int RightMotorBackward = 9;
int state=0;
int to_go=0,countpath=0,countlock=0;
int count_time=0;
int stage=0;
void setup() {
  // put your setup code here, to run once:
for(int x=44;x<53;x++){pinMode(INPUT,x);}//ir
for(int x=7;x<13;x++){pinMode(OUTPUT,x);}//motor
  pinMode(OUTPUT,13);
  digitalWrite(led,LOW);
  Serial.begin(9600);
  Serial1.begin(9600);//blu
}

void loop() {
  // put your main code here, to run repeatedly:
  read_sensor();
 // print_array();
  //check_path();
  


  

switch(stage){
  
  case 0:
  if (Serial1.available()) {
    String a=Serial1.readStringUntil('\n');
    Serial.println(a);
    to_go=a.toInt();
    Serial1.println(to_go);
    if(to_go>0){Serial.println("find path");Serial1.println("go");stage++;
    
    
    }
  
  
  }
  
  break;
  case 1:
    only_forw();
     count_path();
    
   
    if(to_go==countpath){ stage=2; go_stop();
    delay(1000);}
   
  break;
 case 2:
   go_left_fin();
    stage++;
  break; 
  case 3:
   only_forw() ;
 if ( ary[2] == 0 && ary[3] == 0 && ary[4] == 0 && ary[5] == 0 && ary[6] == 0 && ary[7] == 0 ) { stage++;go_stop(); }
    
  break; 
  case 4:
   if (Serial1.available()) {
    String a=Serial1.readStringUntil('\n');
    Serial.println(a);
    to_go=a.toInt();
    Serial1.println(to_go);
    if(to_go==6){Serial.println("fback to");Serial1.println("go");stage++;
    go_back();
    }}
   break;
case 5:
 only_forw() ;
 if ( ary[2] == 0 && ary[3] == 0 && ary[4] == 0 && ary[5] == 0 && ary[6] == 0 && ary[7] == 0 ) { stage=6;go_right();go_stop();
 
 }
  break;

 case 6:
 only_forw() ;
 if (  ary[1] == 1 && ary[2] == 1 && ary[3] == 1 && ary[4] == 1 && ary[5] == 1 && ary[6] == 1 && ary[7] == 1 && ary[8] == 1) { stage=0;go_back();
 go_stop();
  analogWrite(ena, 0);
  analogWrite(enb, 0); }
  break;

  
  
  }


  
  
//Serial.println("");
  
}

void  read_sensor(){
  for(int x=46;x<=53;x++){
  //Serial.print(digitalRead(x));Serial.print(",");
  ary[x-45]=digitalRead(x);
  }
  irR=digitalRead(irR1);
  irL=digitalRead(irL1);
  }
void print_array(){
   for(int y=1;y<=8;y++){
    Serial.print(ary[y]);Serial.print(",");
   }
  Serial.print("/");Serial.print(irL);Serial.print(",");Serial.print(irR);
 
  Serial.println("");}
 
