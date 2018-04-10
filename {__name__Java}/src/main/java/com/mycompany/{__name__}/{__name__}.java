/**
 * file name : App.java
 * Date      :
 * Author    :
 * Description:
 */

//FIXME com.mycompany.app must be changed
package com.mycompany.app;

import java.util.logging.*;


public class {__name__}
{
    private final static Logger logger = Logger.getLogger(Logger.GLOBAL_LOGGER_NAME);

    public static void main( String[] args )
    {
        logger.info("STARTING MAIN");
       
        Calculator cal = new Calculator();

        System.out.println( "Hello World!" );
        int iResult = cal.evaluate("1+3");
        System.out.println( "iResult " + iResult );

        logger.info("ENDING MAIN");
    }
}