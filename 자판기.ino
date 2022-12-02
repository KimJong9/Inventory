#define speed 250
#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,2,3,4,5);
void setup()
{
  lcd.begin(0x3F,16,2);
  lcd.setCursor(0,0);
  lcd.print("0");
  pinMode(13,INPUT);
  pinMode(10, OUTPUT); //dc 거스름돈 배출
  pinMode(9,OUTPUT);  //dc 상품 배출
  pinMode(8,OUTPUT); //rgb red
  pinMode(6,INPUT); // 거스름돈 배출 버튼
  pinMode(7,INPUT); // 상품배출 버튼
  //lcd 핀들 입력
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
}
int count=0;

void loop()
{
  //lcd 함수
  if(count==0){
    lcd.clear();
    lcd.print("vending Machine");

  }//초기 잔액
  else{
    lcd.clear();
    lcd.print(count*100);

  }
  if(count>=2)//red led
    digitalWrite(8,HIGH);
  else
    digitalWrite(8,LOW);
  while (true){
  if(digitalRead(13)==LOW)
  {
    count++;
   delay(500);
   break;
  }
    
  if(digitalRead(6)==HIGH&&count!=0)
  {//거스름돈 배출버튼 누르면
    analogWrite(10,speed);//속도는 일단위에 define에서 조절할 수 있습니다
    lcd.clear();
    lcd.print("receive");
    lcd.setCursor(0,1);
    lcd.print(count*100);
    delay(1000*count);
    count=0;
    analogWrite(10,0);
    break;
  }
  if(digitalRead(7)==HIGH && count>=2)
  {//상품배출버튼 누르면
    analogWrite(9,speed);//속도는 일단위에 define에서 조절할 수 있습니다
    lcd.clear();
    lcd.print("Buy Item");
    delay(1000);
    count=count-2;
    analogWrite(9,0);
    break;
  }
  }
}