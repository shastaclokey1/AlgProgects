function [J] = jacobian(x,y)
    J(1,1) = (2*x);
    J(1,2) = (2*y);
    J(2,1) = -4*(x^3);
    J(2,2) = 3;
end