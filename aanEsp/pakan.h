
void beriPakan()
{
      for(int posisi=0; posisi <=180; posisi++)
  {
    myservo.write(posisi);
    delay(10);
  }
  for(int posisi=180;posisi>=0;posisi--)
  {
    myservo.write(posisi);
    delay(10);
  }

  }
