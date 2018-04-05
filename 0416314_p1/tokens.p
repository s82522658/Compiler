PROGRAM foo(input, output, error) ;
    var id1 : integer;

    function  addition(a, b: integer) : integer;
        begin
            addition := a + b;
        end

    procedure proc(a: real);
        begin
            while a < 10 do
                a := a + 1
        end

    begin
        id1 := 1;
    end.