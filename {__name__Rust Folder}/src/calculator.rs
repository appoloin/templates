

    pub fn add(x:i32, y:i32) -> i32
    {
        trace!("calculator - add - started");

        let i_result:i32 = x + y;

        trace!("calculator - add - end {}", i_result);
        return i_result   
    }


/*********************************************

    UNIT TESTING

**********************************************/
//TODO  UPDATE test

#[cfg(test)]
mod unit_test 
{
    use calculator::*;
    #[test]
    fn add_test() 
    {
        assert_eq!(add(2, 2), 4);
    }
     #[test]
    fn add_test2() 
    {
        assert_ne!(add(2, 2), 2);
    }
}