function [eigenVector, eigenValue, error] = powerMethod(mat,vectInit,tol,maxCount)
    k = 0;
    vectCurr = vectInit;
    vectNext = mat*vectCurr;
    vectNext = vectNext/norm(vectNext);
    err(1) = sqrt(dot(vectNext-vectCurr,vectNext-vectCurr));
    vectCurr = vectNext;
    k = k + 1;
    count = 1;
    while ((err(count) > tol) && (k < maxCount))
        count = count + 1;
        vectNext = mat*vectCurr;
        vectNext = vectNext/norm(vectNext);
        err(count) = sqrt(dot(vectNext-vectCurr,vectNext-vectCurr));
        vectCurr = vectNext;
        k = k + 1;
    end
    if (err(count) > tol)
        disp('Maximum Iterations Exceeded');
    end
    eigenVector = vectCurr;
    matVectorMulted = mat*eigenVector;
    eigenValue = matVectorMulted(1)/eigenVector(1);
    error = err;
end