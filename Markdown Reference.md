[;]: ;

开源硬件指与自由及开放原始码软件相同方式设计的计算机和电子硬件。开源硬件开始考虑对软件以外的领域开源，是开源文化的一部分.

## 第一天：入门

今天的内容是让我们了解什么是开源硬件，老师给我们看的照片中以废物变宝物的理念给了我很大感触。

其中的三个软件是开源硬件所需的：

### arduino：

arduino是一款便捷灵活、方便上手的开源电子原型平台

### processing：

一款专业强大的编程设计软件。这款软件支持主流的java编程结构，界面直观，方便用户创建各类交互式的应用，并且processing代码完全开源，适用于编程开发人员。

### fritzing：

Fritzing是一个开放源码的电路开发软件，它操作简单，使得用户能非常容易的设计他们的电子产品

从老师开始讲代码开始，我就意识到后面的事情肯定不简单！

## 第二天：基础

第二天的学习内容是使用arduino进行编程，了解Morse代码及库函数的形式。

在课堂上，我用Morse代码打了自己的名字，虽然不知道错与对，但是十分的有趣。在写作业时很苦难，因为上课的内容确实没怎么听懂。最后在同学的帮助下，写出了代码：

`char MORSE[][4] = {
  {'.', '-', '*', '*'}, //A
  {'-', '.', '.', '.'}, //B
  {'-', '.', '-', '.'}, //C
  {'-', '.', '.', '*'}, //D
  {'.', '*', '*', '*'}, //E
  {'.', '.', '-', '.'}, //F
  {'-', '-', '.', '*'}, //G
  {'.', '.', '.', '.'}, //H
  {'.', '.', '*', '*'}, //I
  {'.', '-', '-', '-'}, //J
  {'-', '.', '-', '*'}, //K
  {'.', '-', '.', '.'}, //L
  {'-', '-', '*', '*'}, //M
  {'-', '.', '*', '*'}, //N
  {'-', '-', '-', '*'}, //O
  {'.', '-', '-', '.'}, //P
  {'-', '-', '.', '-'}, //Q
  {'.', '-', '.', '*'}, //R
  {'.', '.', '.', '*'}, //S
  {'-', '*', '*', '*'}, //T
  {'.', '.', '-', '*'}, //U
  {'.', '.', '.', '-'}, //V
  {'.', '-', '-', '*'}, //W
  {'-', '.', '.', '-'}, //X
  {'-', '.', '-', '-'}, //Y
  {'-', '-', '.', '.'}  //Z
};
int pin = 13;
void dot() {   digitalWrite(pin, HIGH);   delay(250);   digitalWrite(pin, LOW);   delay(250); }   
void dash() {   digitalWrite(pin, HIGH);   delay(1000);   digitalWrite(pin, LOW);   delay(250); }
void setup() {
  Serial.begin(9600);
   pinMode(pin, OUTPUT); 
}

void loop() {
  String str = ""; 
  String morse = ""; 
  int i, t , temp = 0;
  int n = 0;
  while (Serial.available() > 0) {
    temp = 1;  
    str += char(Serial.read());
    delay(2);
    n++;
  }

  if (temp) {
    for (i = 0; i < n; i++)
    {
      for (t = 0; t < 4; t++)
      {
        if (str[i] >= 97 && str[i] <= 122)
        {
          morse += char(MORSE[int(str[i] - 97)][t]);
        }
      }
      morse += ' ';
    }
    Serial.println(morse);
    for(i=0;i<=4*n;i++)
    {if(morse[i]=='.')
      dot();
     if(morse[i]=='-')
      dash();
    }
  }
  delay(2);
}

void setup()
{
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  Serial.begin(9600);
}
int income=0;
void loop()
{
	if(Serial.available()>0)
    {
    	income=Serial.read();
      	switch(income)
        {
        	case 'f':
          		forward();
          		break;
          	case 'b':
          		backward();
          		break;
          	case 'l':
          		left();
          		break;
          	case 'r':
          		right();
          		break;
          	case 's':
          		stop();
          		break;
          	default:
          		break;
        }
    }
}

`

`void setup()
{
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  Serial.begin(9600);
}
int income=0;
void loop()
{
	if(Serial.available()>0)
    {
    	income=Serial.read();
      	switch(income)
        {
        	case 'f':
          		forward();
          		break;
          	case 'b':
          		backward();
          		break;
          	case 'l':
          		left();
          		break;
          	case 'r':
          		right();
          		break;
          	case 's':
          		stop();
          		break;
          	default:
          		break;
        }
    }
}

void forward()
{
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(9,HIGH);
  digitalWrite(10,LOW);
}

void backward()
{
  digitalWrite(6,HIGH);
  digitalWrite(5,LOW);
  digitalWrite(10,HIGH);
  digitalWrite(9,LOW);
}`

## 第三天：基础

第三天是开始在电脑上模拟电子元件的连接及其操作。刚刚接触觉得很新奇，觉得电脑竟然还能这么用。但是从来就没接触过这个东西的我一操作就懵了，根本不知道从哪里下手。除了打代码之外，连线也根本不会，虽然老师上课讲的很清楚，但从一开始没跟上的我不知道要做些什么！课后同学教我的时候也是迷迷糊糊。课堂上老师说这是小孩子玩的东西让我印象很深，看来我学习的知识面太窄了。最好在同学的帮助下，写出了代码，完成了电子元件模拟的操作。

| byte dalao[10][8] = { |                                                              |
| --------------------- | ------------------------------------------------------------ |
|                       | {0,1,1,1,1,0,1,1}，{0,1,1,0,0,0,0,0}，{0,0,1,1,0,1,1,1}，{0,1,1,1,0,1,0,1},{0,1,1,0,1,1,0,0},{0,1,0,1,1,1,0,1}，{0,1,0,1,1,1,1,1},{0,1,1,1,0,0,0,0},{0,1,1,1,1,1,1,1},{0,1,1,1,1,1,0,1} }; |
|                       | void setup()                                                 |
|                       | {                                                            |
|                       | Serial.begin(9600);                                          |
|                       | for(int i=4;i<=11;i++){                                      |
|                       | pinMode(i, OUTPUT);                                          |
|                       | }                                                            |
|                       | }                                                            |
|                       | int income;                                                  |
|                       | void loop()                                                  |
|                       | {                                                            |
|                       | if(Serial.available()>0)                                     |
|                       | {                                                            |
|                       | income = Serial.read();                                      |
|                       | }                                                            |
|                       | int pin = 4;                                                 |
|                       | switch(income)                                               |
|                       | {                                                            |
|                       | case '0':                                                    |
|                       | for (int s = 0; s < 8; s++)                                  |
|                       | {                                                            |
|                       | digitalWrite(pin, dalao[0][s]);                              |
|                       | pin++;                                                       |
|                       | }                                                            |
|                       | break;                                                       |
|                       | case '1':                                                    |
|                       | for (int s = 0; s < 8; s++)                                  |
|                       | {                                                            |
|                       | digitalWrite(pin, dalao[1][s]);                              |
|                       | pin++;                                                       |
|                       | }                                                            |
|                       | break;                                                       |
|                       | case '2':                                                    |
|                       | for (int s = 0; s < 8; s++)                                  |
|                       | {                                                            |
|                       | digitalWrite(pin, dalao[2][s]);                              |
|                       | pin++;                                                       |
|                       | }                                                            |
|                       | break;                                                       |
|                       | case '3':                                                    |
|                       | for (int s = 0; s < 8; s++)                                  |
|                       | {                                                            |
|                       | digitalWrite(pin, dalao[3][s]);                              |
|                       | pin++;                                                       |
|                       | }                                                            |
|                       | break;                                                       |
|                       | case '4':                                                    |
|                       | for (int s = 0; s < 8; s++)                                  |
|                       | {                                                            |
|                       | digitalWrite(pin, dalao[4][s]);                              |
|                       | pin++;                                                       |
|                       | }                                                            |
|                       | break;                                                       |
|                       | case '5':                                                    |
|                       | for (int s = 0; s < 8; s++)                                  |
|                       | {                                                            |
|                       | digitalWrite(pin, dalao[5][s]);                              |
|                       | pin++;                                                       |
|                       | }                                                            |
|                       | break;                                                       |
|                       | case '6':                                                    |
|                       | for (int s = 0; s < 8; s++)                                  |
|                       | {                                                            |
|                       | digitalWrite(pin, DIGITAL_DISPLAY[6][s]);                    |
|                       | pin++;                                                       |
|                       | }                                                            |
|                       | case '7':                                                    |
|                       | for (int s = 0; s < 8; s++)                                  |
|                       | {                                                            |
|                       | digitalWrite(pin, dalao[7][s]);                              |
|                       | pin++;                                                       |
|                       | }                                                            |
|                       | case '8':                                                    |
|                       | for (int s = 0; s < 8; s++)                                  |
|                       | {                                                            |
|                       | digitalWrite(pin, dalao[8][s]);                              |
|                       | pin++;                                                       |
|                       | }                                                            |
|                       | case '9':                                                    |
|                       | for (int s = 0; s < 8; s++)                                  |
|                       | {                                                            |
|                       | digitalWrite(pin, dalao[9][s]);                              |
|                       | pin++;                                                       |
|                       | }                                                            |
|                       | }                                                            |
|                       | delay(1000);                                                 |
|                       | }                                                            |

![](C:\Users\速度发顺丰\Pictures\QQ图片20190705094802.png)

## 第四天：总结

第四天是进行前面三天总结与答疑的时候，而我在位置上不知所措，草草了解了这门学科，心里面其实没多少疑惑，或者说没懂什么......只是在位置上继续写开始没写完的代码。