<?php

defined('BASEPATH') or exit('No direct script access allowed');

use chriskacerguis\RestServer\RestController;

class Req extends RestController
{

    function __construct($config = 'rest')
    {
        parent::__construct($config);
        $this->load->model('Devices_model');
    }

    function index_get()
    {
        $data = $this->Devices_model->get_devices();
        $this->response($data->result(), 200);
        // $users = [
        //     ['id' => 0, 'name' => 'John', 'email' => 'john@example.com'],
        //     ['id' => 1, 'name' => 'Jim', 'email' => 'jim@example.com'],
        // ];
        // $id = $this->get('id');
        // if ($id == '') {
        //     $this->response($users, 200);
        // } else {
        //     if (array_key_exists($id, $users)) {
        //         $this->response($users[$id], 200);
        //     } else {
        //         $this->response([
        //             'status' => false,
        //             'message' => 'No such user found'
        //         ], 404);
        //     }
        // }
    }

    function index_post()
    {
        $this->response([
            'status' => true,
            'message' => 'Success Post'
        ], 200);
    }

    function index_put()
    {
        $this->response([
            'status' => true,
            'message' => 'Success put'
        ], 200);
    }

    function index_delete()
    {
        $this->response([
            'status' => true,
            'message' => 'Success delete'
        ], 200);
    }


}


?>