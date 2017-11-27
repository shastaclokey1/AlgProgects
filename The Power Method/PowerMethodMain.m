clear;
testMat1 = [9,1,2,3;-3,12,1,-1;0,2,20,5;3,1,-1,-18];
testMat2 = [0,1,0,0,0;1,0,1,0,0;0,1,0,1,0;0,0,1,0,1;0,0,0,1,0];
testMat3 = [100,99,0;0,99,0;0,99,98];
testMat4 = [100,3,0;0,99,0;0,4,98];
testMat5 = [8,3,0;-2,7,0;0,0,4];
testMat6 = (rand(5,5)*100)-50;

guess3 = [1;1;1];
guess4 = [1;1;1;1];
guess5 = [1;1;1;1;1];


disp('Testing Pow on Mat1')
[Eve1,Eva1,err1] = powerMethod(testMat1,guess4,.1,100);
if (det(testMat1) ~= 0)
    [Eve1in,Eva1in,err1in] = powerMethod(inv(testMat1),guess4,.1,100);
    show = 1;
else
    disp('Mat1 is non Invertable')
    show = 0;
end
disp('Largest Eigen Value:')
disp(Eva1)
disp('Eigen Vector:')
disp(Eve1)
disp('Error:')
disp(err1(length(err1)))
if (show == 1)
    disp('Smallest Eigen Value:')
    disp(1/Eva1in)
    disp('Eigen Vector:')
    disp(Eve1in)
    disp('Error:')
    disp(err1in(length(err1in)))
    figure;
    plot(linspace(1,length(err1in),length(err1in)),err1in,'k.','MarkerSize',25)
    title 'matrix one error Smallest EV'
end
figure;
plot(linspace(1,length(err1),length(err1)),err1,'k.','MarkerSize',25)
title 'matrix one error Largest EV'



disp(' ')
disp(' ')
disp('Testing Pow on Mat2')
[Eve2,Eva2,err2] = powerMethod(testMat2,guess5,.1,100);
if (det(testMat2) ~= 0)
    [Eve2in,Eva2in,err2in] = powerMethod(inv(testMat2),guess5,.1,100);
    show = 1;
else
    disp('Mat2 is non Invertable')
    show = 0;
end
disp('Largest Eigen Value:')
disp(Eva2)
disp('Eigen Vector:')
disp(Eve2)
disp('Error:')
disp(err2(length(err2)))
if (show == 1)
    disp('Smallest Eigen Value:')
    disp(1/Eva2in)
    disp('Eigen Vector:')
    disp(Eve2in)
    disp('Error:')
    disp(err2in(length(err2in)))
    figure;
    plot(linspace(1,length(err2in),length(err2in)),err2in,'k.','MarkerSize',25)
    title 'matrix two error Smallest EV'
end
figure;
plot(linspace(1,length(err2),length(err2)),err2,'k.','MarkerSize',25)
title 'matrix two error Largest EV'


disp(' ')
disp(' ')
disp('Testing Pow on Mat3')
[Eve3,Eva3,err3] = powerMethod(testMat3,guess3,.1,100);
if (det(testMat3) ~= 0)
    [Eve3in,Eva3in,err3in] = powerMethod(inv(testMat3),guess3,.1,100);
    show = 1;
else
    disp('Mat3 is non Invertable')
    show = 0;
end
disp('Largest Eigen Value:')
disp(Eva3)
disp('Eigen Vector:')
disp(Eve3)
disp('Error:')
disp(err3(length(err3)))
if (show == 1)
    disp('Smallest Eigen Value:')
    disp(1/Eva3in)
    disp('Eigen Vector:')
    disp(Eve3in)
    disp('Error:')
    disp(err3in(length(err3in)))
    figure;
    plot(linspace(1,length(err3in),length(err3in)),err3in,'k.','MarkerSize',25)
    title 'matrix three error Smallest EV'
end
figure;
plot(linspace(1,length(err3),length(err3)),err3,'k.','MarkerSize',25)
title 'matrix three error Largest EV'


disp(' ')
disp(' ')
disp('Testing Pow on Mat4')
[Eve4,Eva4,err4] = powerMethod(testMat4,guess3,.1,100);
if (det(testMat4) ~= 0)
    [Eve4in,Eva4in,err4in] = powerMethod(inv(testMat4),guess3,.1,100);
    show = 1;
else
    disp('Mat4 is non Invertable')
    show = 0;
end
disp('Largest Eigen Value:')
disp(Eva4)
disp('Eigen Vector:')
disp(Eve4)
disp('Error:')
disp(err4(length(err4)))
if (show == 1)
    disp('Smallest Eigen Value:')
    disp(1/Eva4in)
    disp('Eigen Vector:')
    disp(Eve4in)
    disp('Error:')
    disp(err4in(length(err4in)))
    figure;
    plot(linspace(1,length(err4in),length(err4in)),err4in,'k.','MarkerSize',25)
    title 'matrix four error Smallest EV'
end
figure;
plot(linspace(1,length(err4),length(err4)),err4,'k.','MarkerSize',25)
title 'matrix four error Largest EV'


disp(' ')
disp(' ')
disp('Testing Pow on Mat5')
[Eve5,Eva5,err5] = powerMethod(testMat5,guess3,.1,100);
if (det(testMat5) ~= 0)
    [Eve5in,Eva5in,err5in] = powerMethod(inv(testMat5),guess3,.1,100);
    show = 1;
else
    disp('Mat5 is non Invertable')
    show = 0;
end
disp('Largest Eigen Value:')
disp(Eva5)
disp('Eigen Vector:')
disp(Eve5)
disp('Error:')
disp(err5(length(err5)))
if (show == 1)
    disp('Smallest Eigen Value:')
    disp(1/Eva5in)
    disp('Eigen Vector:')
    disp(Eve5in)
    disp('Error:')
    disp(err5in(length(err5in)))
    figure;
    plot(linspace(1,length(err5in),length(err5in)),err5in,'k.','MarkerSize',25)
    title 'matrix five error Smallest EV'
end
figure;
plot(linspace(1,length(err5),length(err5)),err5,'k.','MarkerSize',25)
title 'matrix five error Largest EV'


disp(' ')
disp(' ')
disp('Testing Pow on Mat6')
[Eve6,Eva6,err6] = powerMethod(testMat6,guess5,.1,100);
if (det(testMat6) ~= 0)
    [Eve6in,Eva6in,err6in] = powerMethod(inv(testMat6),guess5,.1,100);
    show = 1;
else
    disp('Mat6 is non Invertable')
    show = 0;
end
disp('Largest Eigen Value:')
disp(Eva6)
disp('Eigen Vector:')
disp(Eve6)
disp('Error:')
disp(err6(length(err6)))
if (show == 1)
    disp('Smallest Eigen Value:')
    disp(1/Eva6in)
    disp('Eigen Vector:')
    disp(Eve6in)
    disp('Error:')
    disp(err6in(length(err6in)))
    figure;
    plot(linspace(1,length(err6in),length(err6in)),err6in,'k.','MarkerSize',25)
    title 'matrix six error Smallest EV'
end
figure;
plot(linspace(1,length(err6),length(err6)),err6,'k.','MarkerSize',25)
title 'matrix six error Largest EV'