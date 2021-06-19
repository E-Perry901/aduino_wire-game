#include <arduino.h>

int output_to_wire = 3;
int main_input_pin = 4;
int led_lives_display[3] = {8,9,10};

int lives_left = 3;
int led_counter = 2;
int inp_value;

void start () {
    delay(500);

    while (true)
    {
        inp_value = digitalRead(main_input_pin);
        Serial.println(inp_value);

        if (inp_value == 1)
        {
            return touched();
        }
    }
}

void touched () {
    lives_left--;
    digitalWrite(led_lives_display[led_counter], LOW);
    led_counter--;

    if (lives_left == 0)
    {
        return dead();
    }
    
    else {
        delay(750);
        start();
    }
}

void dead () {
    delay(500);
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            digitalWrite(led_lives_display[j], HIGH);
        }
            delay(150);

        for (int j = 0; j < 3; j++)
        {
            digitalWrite(led_lives_display[j], LOW);
        }
        delay(150);
    }

    delay(2000);
    start();
}

void setup () {
    Serial.begin(9600);
    for (int i = 0; i < 3; i++)
    {
        pinMode(led_lives_display[i], OUTPUT);
        digitalWrite(led_lives_display[i], HIGH);
    }
    
    pinMode(main_input_pin, INPUT);
    pinMode(output_to_wire, OUTPUT);
    digitalWrite(output_to_wire, HIGH);
    start();
}

void loop () {

}
