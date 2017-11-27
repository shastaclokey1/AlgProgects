function [estimatedRoot,errorArray] = newtonSys(xinit,tol)
    xOld = xinit;
    h = -jacobian(xOld(1),xOld(2))\dualFunct(xOld(1),xOld(2));
    xNew = xOld + h';
    conMeasure = abs(xNew - xOld);
    xOld = xNew;
    while (conMeasure(1) > tol || conMeasure(2) > tol) 
        h = -jacobian(xOld(1),xOld(2))\dualFunct(xOld(1),xOld(2));
        xNew = xOld + h';
        conMeasure = abs(xNew - xOld);
        xOld = xNew;
    end
    estimatedRoot = xOld;
    errorArray = newtonSysError(xinit,tol,estimatedRoot);
end