% Demimal to Any

% Subhajit Sahu
% 110EC0181


while(1)
    prompt={'Enter a Decimal Number:', 'Enter the Resultant Number base:'};
    name='Decimal To Any(Subhajit Sahu[110EC0181])';
    numlines=1;
    defaultanswer={'',''};
    answer=inputdlg(prompt,name,numlines,defaultanswer);
    y = uint32(str2double(answer(1)));
    b = uint32(str2double(answer(2)));
    s = uint32(zeros(1,256));
    i = 1;
    while(y)
        z = mod(y, b);
        if(z <= 9)
            s(1,i) = '0' + z;
        else
            s(1,i) = 'A' + (z - 10);
        end
        y = (y - z)/b;
        i = i + 1;
    end
    m = i;
    t = s;
    while(i >= 2)
        i = i - 1;
        t(1, m-i) = s(1, i);
    end
    s = char(t);
    s = msgbox(s, 'Number in requested Base');
    waitfor(s);
    choice = questdlg('Would you like to continue with another number?', 'Decimal To Any(Subhajit Sahu [110EC0181])', 'Yes', 'No', 'No');
    if(strcmp(choice, 'No'))
        break;
    end
end


