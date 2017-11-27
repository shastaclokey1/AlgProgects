function [] = testingNewton(guess)
    %%%%%%%%%%%%%%%%single equation%%%%%%%%%%%%%%%
    [estimatedRoot,errorArray] = newton(guess,.000000000000001);

    disp(estimatedRoot)

    figure;
    plot(errorArray, '.k','MarkerSize', 25)
    ttl = strcat('Error Plot Single Equation, guess = ', num2str(guess));
    title(ttl);
    
    logErrorArray = log(log(errorArray));
    logIndicies = log(linspace(1,length(logErrorArray),length(logErrorArray)));

    figure;
    plot(logIndicies, logErrorArray, '.r','MarkerSize', 25)
    ttl = strcat('Log Error Plot Single Equation, guess = ', num2str(guess));
    title(ttl);


end