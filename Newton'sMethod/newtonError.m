function [errorArray] = newtonError(xinit,tol,trueVal)
    xOld = xinit;
    count = 1;
    
    [currentFval,currentDFval] = funct(xOld);
    xNew = xOld - (currentFval/currentDFval);
    conMeasure = abs(xNew - xOld);
    xOld = xNew;
    tempArray(count) = abs(xOld - trueVal);
    count = count + 1;
    
    while (conMeasure > tol) 
        [currentFval,currentDFval] = funct(xOld);
        xNew = xOld - (currentFval/currentDFval);
        conMeasure = abs(xNew - xOld);
        xOld = xNew;
        tempArray(count) = abs(xOld - trueVal);
        count = count + 1;
    end
    errorArray = tempArray;
end
