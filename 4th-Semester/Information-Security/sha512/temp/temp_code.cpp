void round_test_function(){
    initialize();
    print_8_registers(-1);

    printf("Testing input module:%s\n",DIVIDER);
    printf("Enter text to hash:\n");
    char* input_str = take_input();
    message_schedeule(convert_input_to_int64_arr(input_str));

    print_message_schedeule();
    all_80_rounds(); 
    
    printf("Final message digest:\n");
    print_8_registers(-1);
}
