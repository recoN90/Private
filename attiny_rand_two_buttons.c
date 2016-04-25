// Includes


// Pins
#define BUTTON  0
#define OPT_1   1
#define OPT_2   3
#define OPT_3   5
#define OPT_4   7
#define OPT_5   9
#define OPT_6   2
#define OPT_7   4
#define OPT_8   6
#define OPT_9   8
#define OPT_10  10

#define HIGH    1
#define LOW     0

// Variables
int OPT[] = {OPT_1, OPT_2, OPT_3, OPT_4, OPT_5, OPT_6, OPT_7, OPT_8, OPT_9, OPT_10};
int LEFT[] = {OPT_1, OPT_2, OPT_3, OPT_4, OPT_5};
int RIGHT[] = {OPT_6, OPT_7, OPT_8, OPT_9, OPT_10};
int current_random = 0;
int label = 0;
int ButtonVal;
int options = 10;
bool up = false;
int Button[2][3] = {{1, 900},   // button 1
                    {2, 800}};  // button 2

void setup(){
  pinMode(BUTTON, INPUT);
  
  pinMode(OPT_1, OUTPUT);
  pinMode(OPT_2, OUTPUT);
  pinMode(OPT_3, OUTPUT);
  pinMode(OPT_4, OUTPUT);
  pinMode(OPT_5, OUTPUT);
  pinMode(OPT_6, OUTPUT);
  pinMode(OPT_7, OUTPUT);
  pinMode(OPT_8, OUTPUT);
  pinMode(OPT_9, OUTPUT);
  pinMode(OPT_10, OUTPUT);
  
  start_up();
  all(LOW);
}

void loop(){
  
  ButtonVal = analogRead(BUTTON);
  ButtonCheck();
  
  if (label == 1 && up == false){
    all(LOW);
    options++;
    if(options == 11){
      options = 1;
      up = true;
    }
    for (int i = 0; i <= options; i++){
      digitalWrite(OPT[i], HIGH);
    }
    down = false;
  }else if (label == 2 && up == false){
    all(LOW);
    current_random = random(1, options+1);
    if(current_random == 1) select(1);
    else if(current_random == 2) select(2);
    else if(current_random == 3) select(3);
    else if(current_random == 4) select(4);
    else if(current_random == 5) select(5);
    else if(current_random == 6) select(6);
    else if(current_random == 7) select(7);
    else if(current_random == 8) select(8);
    else if(current_random == 9) select(9);
    else if(current_random == 10) select(10);
    up = true;
  }
  delay(20);
}

void ButtonCheck(){
  for(int i = 0; i <= 2; i++){
    int temp2 = ButtonVal/100 * 100;
    if(temp2 == Button[i][1]){
      label = Button[i][0];
    }else {
      label = 0;
      up = false;
    }
  }
}

void select(int value){
  all(LOW);
  // durchlauf bis zur auswahl
  for (int x = 0; x < 4; x++){
    for (int i = 0; i <= 5; i++){
      digitalWrite(LEFT[i], HIGH);
      digitalWrite(RIGHT[i], HIGH);
      digitalWrite(LEFT[i-1], LOW);
      digitalWrite(RIGHT[i-1], LOW);
      delay(20);
    }
  }
  
  int temp = value;
  
  if (temp > 5) temp = temp-5;
  
  for (int y = 0; y <= temp; y++){
    digitalWrite(LEFT[y], HIGH);
    digitalWrite(RIGHT[y], HIGH);
    digitalWrite(LEFT[y-1], LOW);
    digitalWrite(RIGHT[y-1], LOW);
    delay(20);
  }
  
  all(LOW);
  digitalWrite(OPT[value], HIGH);
}

void all(int value){
  for (int i = 0; i < 10; i++){
    digitalWrite(OPT[i], value);
  }
}

void start_up(){
  all(LOW);
  delay(30);
  
  for (int i=0; i < 5; i++){
    digitalWrite(LEFT[i], HIGH);
    digitalWrite(RIGHT[i], HIGH);
    delay(50);
  }
  for (int i=0; i < 5; i++){
    digitalWrite(LEFT[i], LOW);
    digitalWrite(RIGHT[i], LOW);
    delay(50);
  }
  delay(100);
  all(LOW);
  delay(40);
  all(HIGH);
  delay(50);
}
