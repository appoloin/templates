//FIXME change com.mycompany.app
package com.mycompany.app;

import org.junit.jupiter.api.*;
import static org.junit.jupiter.api.Assertions.assertEquals;

class CalculatorTest 
{
	Calculator cal = new Calculator();
  
	@Test
    void myFirstTest() 
    {       
        int i = cal.evaluate("1+2");
        assertEquals(i, 4);
    }

    @Test
    void mySecondTest() 
    {       
        int i = cal.evaluate("1+2");
        assertEquals(i, 3);
    }

}