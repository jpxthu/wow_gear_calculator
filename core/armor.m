a = 1 : 20000;
r = a ./ (a + 400 + 85 * 63);
r = min(r, 0.75);
% drda = 1 ./ (a + 400 + 85 * 63) - a ./ (a + 400 + 85 * 63) .^ 2;
drda2 = [0, r(2:end) - r(1:end-1)];

figure

ax(1) = subplot(3, 1, 1);
plot(a, r, 'LineWidth', 2)
grid on
title('Armor damage reduction')
ylabel('reduction')

ax(2) = subplot(3, 1, 2);
plot(a, 0.01 ./ drda2, 'LineWidth', 2)
grid on
title('Addition armor needed for 1% reduction')
ylabel('addition armor')

ax(3) = subplot(3, 1, 3);
plot(a, (1 - r) * 0.01 ./ drda2, 'LineWidth', 2)
grid on
xlabel('armor')

linkaxes(ax, 'x')
