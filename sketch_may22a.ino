long duration;

int distance1;
int distance2;

// ENTRY SENSOR
int trig1 = 2;
int echo1 = 3;

// EXIT SENSOR
int trig2 = 4;
int echo2 = 5;

// Counters
int entryCount = 0;
int exitCount = 0;
int peopleInside = 0;

void setup()
{
    pinMode(trig1, OUTPUT);
    pinMode(echo1, INPUT);

    pinMode(trig2, OUTPUT);
    pinMode(echo2, INPUT);

    Serial.begin(9600);
}

void loop()
{
    // -------- ENTRY SENSOR --------

    digitalWrite(trig1, LOW);
    delayMicroseconds(2);

    digitalWrite(trig1, HIGH);
    delayMicroseconds(10);

    digitalWrite(trig1, LOW);

    duration = pulseIn(echo1, HIGH);

    distance1 = duration * 0.034 / 2;

    // -------- EXIT SENSOR --------

    digitalWrite(trig2, LOW);
    delayMicroseconds(2);

    digitalWrite(trig2, HIGH);
    delayMicroseconds(10);

    digitalWrite(trig2, LOW);

    duration = pulseIn(echo2, HIGH);

    distance2 = duration * 0.034 / 2;

    // -------- ENTRY DETECTION --------

    if (distance1 < 5)
    {
        entryCount++;
        peopleInside++;

        Serial.println("Person Entered");
        Serial.print("Total Entries: ");
        Serial.println(entryCount);

        Serial.print("People Inside Room: ");
        Serial.println(peopleInside);

        Serial.println("----------------");

        delay(1000);
    }

    // -------- EXIT DETECTION --------

    if (distance2 < 5)
    {
        exitCount++;

        if (peopleInside > 0)
        {
            peopleInside--;
        }

        Serial.println("Person Exited");
        Serial.print("Total Exits: ");
        Serial.println(exitCount);

        Serial.print("People Inside Room: ");
        Serial.println(peopleInside);

        Serial.println("----------------");

        delay(1000);
    }
}