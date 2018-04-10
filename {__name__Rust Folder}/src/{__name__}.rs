/*
    File Name   = {__name__}
    Date        = {__date__}
    Author      = 
    Description =    
*/

#[macro_use]
extern crate log;
extern crate simple_logger; 

mod calculator;

fn main() 
{
    //log::LogLevel::Warn
    simple_logger::init_with_level(log::Level::Trace).unwrap();
    trace!("MAIN - started");

    let i_result = calculator::add(1, 4);
    trace!("MAIN - i_result {}",i_result);

    trace!("MAIN - END");
}