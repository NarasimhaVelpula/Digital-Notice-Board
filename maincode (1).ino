#include <dht.h>
#include <LiquidCrystal.h>
dht DHT;
LiquidCrystal lcd(7,6,5,4,3,2);
LiquidCrystal lcd2(7,13,11,10,9,8);
#define dhtPin 12
#define ssid "srihari"
#define pass "srihari4927"
#define api "ecourses.aec.edu.in"
#define bodrate 115200

String GET="GET http://ecourses.aec.edu.in/thub/notice%20board/show.php";
bool updated;
String year="",mon="",dd="",date="";
String msg;
    String day;
    int len;
void setup()
{
  // put your setup code here, to run once:
  
lcd.begin(16,4);
lcd.clear();
lcd2.begin(20,4);
lcd2.clear();
 
    lcd2.setCursor(0,0);
   lcd2.print("initialising......");
Serial.begin(bodrate);
lcd.setCursor(0,0);
   lcd.print("wifi connecting..");
Serial.println("AT");
delay(1000);
if(Serial.find("OK"))
{
  bool connected=connectwifi();
  if(connected)
  {
    lcd.clear();
   lcd.setCursor(0,0);
   lcd.print("wifi connected");
   delay(500);
  }
  else
  {
    lcd.setCursor(0,0);
   lcd.print("wifi unconnected");
   delay(500);
  }
  
}
pinMode(dhtPin,OUTPUT);      
}
void loop() 
{
  // put your main code here, to run repeatedly:
  String note=status_Checker();
  date="Date:"+dd+"-"+mon+"-"+year;
  Serial.println(date);
  delay(500);
   DHT.read11(12);
  double temp=DHT.temperature;
  String temperature="Temperature:";
  temperature+=temp;
  delay(200);
  Serial.println(temp);
 day="Day:"+day;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("*ECE Department*");
   lcd.setCursor(0,1);
   lcd.print(date);
  
   lcd.setCursor(0,2);
   lcd.print(day);
 
    lcd.setCursor(0,3);
   lcd.print(temperature);
   delay(500);
   int wid=msg.length();
   String line1="",line2="",line3="",line4="";
   for(int i=0;i<20&i<wid;i++)
   line1+=msg[i];
   if(wid>20)
   {
   for(int i=20;i<40&i<wid;i++)
   line2+=msg[i];
   }else
    line2=" ";
    if(wid>40)
    {
   for(int i=40;i<60&i<wid;i++)
   line3+=msg[i];
    }
    else
    line3=" ";
   for(int i=60;i<wid;i++)
   line4+=msg[i];
  lcd2.clear();
    lcd2.setCursor(0,0);
   lcd2.print(line1);
  
    lcd2.setCursor(0,1);
   lcd2.print(line2);

    lcd2.setCursor(0,2);
   lcd2.print(line3);
 
    lcd2.setCursor(0,3);
   lcd2.print(line4);
   delay(500);
  Serial.println(msg);
   Serial.println(line1);
    Serial.println(line2);
     Serial.println(line3);
      Serial.println(line4);
 day="";
}
bool connectwifi()
{
  Serial.println("AT+CWMODE=1");
  delay(5000);
  String cmd="AT+CWJAP=\"";
  cmd+=ssid;
  cmd+="\",\"";
  cmd+=pass;
  cmd+="\"";
  Serial.println(cmd);  
  delay(5000);
  if(Serial.find("OK"))
  {
    return true;
  }
  else
  {
    return false;
  }
}

  String status_Checker()
  {
    String data;
    delay(1000);
    String cmd="AT+CIPSTART=\"TCP\",\"";
  cmd+=api;
  cmd+="\",80";
  Serial.println(cmd);
  delay(3000);
 
  if(Serial.find("Error"))
  {
    
    Serial.print("AT+CIPCLOSE");
    return "none";
  }
   String cmd1=GET;
   cmd1+="\r\n";
  Serial.print("AT+CIPSEND=");
  Serial.println(cmd1.length());
  delay(5000);
  if(Serial.find(">"))
  {
    
     
    Serial.println(cmd1);
    String data=Serial.readString();
     Serial.print("AT+CIPCLOSE");
  
   
    day="";
    Serial.println(data);
    len=data.length();
    year="";
    mon="";
    dd="";
    for(int i=53;i<57;i++)
    {
      year+=data[i];
    }
    for(int i=58;i<60;i++)
    {
      mon+=data[i];
    }
    for(int i=61;i<63;i++)
    {
      dd+=data[i];
    }
  
    if(data[63]=='W')
    {
       msg="";
      for(int i=72;i<len-8;i++)
    {
      msg+=data[i];
    }
    
      day="Wednesday";
    }
      if(data[63]=='M')
     {
       msg="";
      for(int i=69 ;i<len-8;i++)
    {
      msg+=data[i];
    }
      day="Monday";
     }
      if(data[63]=='F')
      {
         msg="";
        for(int i=69;i<len-8;i++)
    {
      msg+=data[i];
    }
      
      day="Friday";
      }
      if(data[63]=='S')
      {
         msg="";
        if(data[64]=='u')
        {
          for(int i=69;i<len-8;i++)
    {
      msg+=data[i];
    }
          day="Sunday";
        }
          else
          {
            for(int i=71;i<len-8;i++)
    {
      msg+=data[i];
    }
          day="Saturday";
          }
      }
       if(data[63]=='T')
     {
       msg="";
        if(data[64]=='u')
        {
          for(int i=70;i<len-8;i++)
    {
      msg+=data[i];
    }
          day="Tuesday";
        }
          else
          {
            for(int i=71;i<len-8;i++)
    {
      msg+=data[i];
    }
          day="THURSDAY";
          }
      }
  }
    
   else
   {
    return("none");
   }
 
  return (data);
}


