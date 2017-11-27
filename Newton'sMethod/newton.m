function [estimatedRoot,errorArray] = newton(xinit,tol)
    xOld = xinit;
    [currentFval,currentDFval] = funct(xOld);
    xNew = xOld - (currentFval/currentDFval);
    conMeasure = abs(xNew - xOld);
    xOld = xNew;
    while (conMeasure > tol) 
        [currentFval,currentDFval] = funct(xOld);
        xNew = xOld - (currentFval/currentDFval);
        conMeasure = abs(xNew - xOld);
        xOld = xNew;
    end
    estimatedRoot = xOld;
    errorArray = newtonError(xinit,tol,estimatedRoot);
end

