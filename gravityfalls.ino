double _ABVAR_1_distance = 0.0 ;
int _ABVAR_2_timer = 0 ;
double _ABVAR_3_acceleration = 0.0 ;
unsigned long _ABVAR_4_2000000 = 0UL ;

void setup()
{
  pinMode( 10, INPUT);
  pinMode( 6, INPUT);
  pinMode( 2 , OUTPUT);
  pinMode( 6 , OUTPUT);
  pinMode( 10 , OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  _ABVAR_1_distance = 1.01 ;
  digitalWrite( 2 , LOW );
  digitalWrite( 6 , HIGH );
  digitalWrite( 10 , HIGH );
  if (( ( digitalRead(6) ) == ( LOW ) ))
  {
    digitalWrite( 2 , HIGH );
    delay( 4000 );
    digitalWrite( 2 , LOW );
    _ABVAR_2_timer = 0 ;
    while ( ( ( digitalRead(10) ) != ( LOW ) ) )
    {
      _ABVAR_2_timer = ( _ABVAR_2_timer + 1 ) ;
      delay( 1 );
    }

    Serial.print("time (ms)");
    Serial.print(_ABVAR_2_timer);
    Serial.println();
    _ABVAR_3_acceleration = ( ( 2000000 * _ABVAR_1_distance ) / pow( _ABVAR_2_timer ,2 ) ) ;
    Serial.print("Accelration due to gravity =");
    Serial.print(_ABVAR_3_acceleration);
    Serial.println();
  }
}


