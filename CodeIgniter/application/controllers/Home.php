<?php
defined('BASEPATH') or exit('No direct script access allowed');

class Home extends CI_Controller
{
    function __construct($config = 'rest')
    {
        parent::__construct($config);
        $this->load->model('Devices_model');
    }

    public function index()
    {
        $data['devices'] = $this->Devices_model->get_devices();
        $this->load->view('home_view', $data);
    }
    public function update()
    {
        $idDevices = $this->input->post('idDevices');
        $this->Devices_model->update($idDevices);
        redirect('home');
    }
}