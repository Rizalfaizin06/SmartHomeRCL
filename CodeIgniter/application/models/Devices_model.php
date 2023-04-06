<?php

class Devices_model extends CI_Model
{
    public function get_devices()
    {
        $result = $this->db->get('devices');
        return $result;
    }

    public function update($idDevices)
    {
        $this->db->set('status', 'NOT status', FALSE);
        $this->db->where('id', $idDevices);
        $this->db->update('devices');
    }
}