#include <Arduino.h>
#include "AdjacencyList.h"
#include <LiquidCrystal.h>
#include "LcdKeys.h"
#include "MemoryFree.h"

extern HardwareSerial Serial;
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
const int numRows = 2;
const int numColumns = 16;
const int arrayLength = 18;
int lastButton;
int lcd_key = 0;
int adc_key_in = 0;
sbyte selectIndex;
byte selectIndexY;
PokeType moveType;
PokeType pokeType;
AdjacencyList *adjacencyList;

void setup()
{
	Serial.begin(9600);
	Serial.println("starting");
	lcd.begin(numRows, numColumns);
	lcd.clear();

	Serial.print("free memory: ");
	Serial.println(freeMemory());
	adjacencyList = AdjacencyList::Create();
	Serial.print("free memory: ");
	Serial.println(freeMemory());
	lcd.setCursor(0, 0);
	lcd.print(pokeTypes::getEnumMap(moveType));
	lcd.print("-");
	lcd.setCursor(0, 1);
	lcd.print(pokeTypes::getEnumMap(pokeType));

	Serial.println("completed");
}

void loop()
{
	adc_key_in = analogRead(0);
	lcd_key = lcdKeys::read_LCD_buttons(adc_key_in);

	if (lcd_key == lastButton)
		return;

	// Serial.print("new input: ");
	// Serial.println(adc_key_in);
	// Serial.println(lcd_key);
	switch (lcd_key)
	{
	case btnRight:
	{
		Serial.println("RIGHT");
		break;
	}
	case btnLeft:
	{
		Serial.println("LEFT");
		break;
	}
	case btnUp:
	{
		selectIndex++;
		if (selectIndex >= arrayLength)
			selectIndex = 0;
		if (!selectIndexY)
			moveType = (PokeType)selectIndex;
		else
			pokeType = (PokeType)selectIndex;
		Serial.println("UP");
		Serial.println(pokeTypes::getEnumMap(selectIndex));
		lcd.setCursor(0, selectIndexY);
		lcd.print(pokeTypes::getEnumMap(selectIndex));
		lcd.print((char)45);
		break;
	}
	case btnDown:
	{
		selectIndex--;
		if (selectIndex < 0)
			selectIndex = arrayLength - 1;
		if (!selectIndexY)
			moveType = (PokeType)selectIndex;
		else
			pokeType = (PokeType)selectIndex;
		Serial.println("DOWN");
		lcd.setCursor(0, selectIndexY);
		lcd.print(pokeTypes::getEnumMap(selectIndex));
		lcd.print((char)45);
		break;
	}
	case btnSelect:
	{
		lcd.setCursor(3, selectIndexY);
		lcd.print(" ");
		selectIndexY = !selectIndexY;
		selectIndex = selectIndexY ? pokeType : moveType;
		lcd.setCursor(3, selectIndexY);
		lcd.print("-");
		Serial.println("SELECT");
		break;
	}
	case btnNone:
	{
		Serial.println("NONE");
		break;
	}
	}
	auto multiplier = adjacencyList->GetAttackMultiplier(moveType, pokeType);
	lcd.setCursor(5, 1);
	lcd.print(multiplier, 1);
	lastButton = lcd_key;
}