function [duo] = dualFunct(x,y)
    f =  (x^2) + (y^2) - 4;
    g = (3*y) - (x^4);
    duo = [f;g];
end