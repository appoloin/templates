package com.mycompany.app;

import java.util.logging.*;

public class Calculator 
{
    private final static Logger logger = Logger.getLogger(Logger.GLOBAL_LOGGER_NAME);

    public int evaluate(String expression) 
    {
        logger.info("STARTING evaluate");
        int sum = 0;
        for (String summand: expression.split("\\+"))
            sum += Integer.valueOf(summand);
            
            logger.info("ENDING evaluate - " + sum );
        return sum;
    }
  }