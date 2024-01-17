void forward() {
  analogWrite(enA, 85);
  analogWrite(enB, 85);

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}
void left() {
  analogWrite(enA, 60);
  analogWrite(enB, 60);

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}
void right() {
  analogWrite(enA, 60);
  analogWrite(enB, 60);

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
void stop() {
  analogWrite(enA, 85);
  analogWrite(enB, 85);

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
void rev(){
   analogWrite(enA, 85);
  analogWrite(enB, 85);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH); 
}
