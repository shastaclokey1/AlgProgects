function [errorArray] = newtonSysError(xinit,tol,trueVal)
    xOld = xinit;
    count = 1;
    
    h = -jacobian(xOld(1),xOld(2))\dualFunct(xOld(1),xOld(2));
    xNew = xOld + h';
    conMeasure = abs(xNew - xOld);
    xOld = xNew;
    tempArray(count) = norm(xOld - trueVal);
    count = count + 1;
    
    while (conMeasure(1) > tol || conMeasure(2) > tol) 
        h = -jacobian(xOld(1),xOld(2))\dualFunct(xOld(1),xOld(2));
        xNew = xOld + h';
        conMeasure = abs(xNew - xOld);
        xOld = xNew;
        tempArray(count) = norm(xOld - trueVal);
        count = count + 1;
    end
    errorArray = tempArray;
end