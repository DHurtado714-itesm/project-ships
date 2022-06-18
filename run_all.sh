g++ main.cpp -o app
mkdir my_outputs
for i in 0 1 2 3 4 6
do
  ./app ./test_cases/input$i.txt ./my_outputs/out$i.txt
  diff ./test_cases/output$i.txt ./my_outputs/out$i.txt
done