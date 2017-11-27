function [] = testingNewtonSys(guessX, guessY)

    %%%%%%%%%%%%%%%System of two equations%%%%%%%%%%%%
    [estRoot,errArray] = newtonSys([guessX,guessY],.000000000000001);

    disp(estRoot)

    figure;
    plot(errArray, '.k','MarkerSize', 25)
    ttl = strcat('Error Plot Sys of Equations, guessX = ', num2str(guessX));
    ttl = strcat(ttl,', guessY = ');
    ttl = strcat(ttl,num2str(guessY));
    title(ttl);

    logErrArray = log(log(errArray));
    logIndi = log(linspace(1,length(logErrArray),length(logErrArray)));

    figure;
    plot(logIndi, logErrArray, '.r','MarkerSize', 25)
    ttl = strcat('Log Error Plot Sys of Equations, guessX = ', num2str(guessX));
    ttl = strcat(ttl,', guessY = ');
    ttl = strcat(ttl,num2str(guessY));
    title(ttl);

end