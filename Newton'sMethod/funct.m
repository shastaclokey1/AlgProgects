function [f, df] = funct(x)
    %f =  (x^4) - (6*(x^2)) + 8;
    %f =  (x^4) - (6*(x^2)) + 9;
    %f = (x^3) - (6*(x^2)) + 9;
    f = (x^4) + (3*(x^2)) + 2;
    %df = 4*(x^3) - (12*x);
    %df = 4*(x^3) - (12*x);
    %df = 3*(x^2) - (12*x);
    df = 4*(x^3) - (6*x);
end